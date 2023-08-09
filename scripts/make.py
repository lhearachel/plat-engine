#!/usr/bin/env python3

import os
import subprocess
import struct
import sys
import typing
import _io
import ndspy.codeCompression

#OFFSET_START = 0x023C8000 + 0x4000 # 0x4000 is the offset in the synthetic overlay.  change to where you need it to be.

if sys.platform.startswith('win'):
    PathVar = os.environ.get('Path')
    Paths = PathVar.split(';')
    PATH = ''
    for candidatePath in Paths:
        if 'devkitARM' in candidatePath:
            PATH = candidatePath
            break
    if PATH == '':
        PATH = 'C://devkitPro//devkitARM//bin'
        if os.path.isdir(PATH) is False:
            print('Devkit not found.')
            sys.exit(1)

    PREFIX = 'arm-none-eabi-'
    OBJDUMP = os.path.join(PATH, PREFIX + 'objdump')
    NM = os.path.join(PATH, PREFIX + 'nm')
    AS = os.path.join(PATH, PREFIX + 'as')

else:  # Linux, OSX, etc.
    if os.path.exists('/opt/devkitpro/devkitARM/bin/'):
        PREFIX = '/opt/devkitpro/devkitARM/bin/arm-none-eabi-'
    else:
        PREFIX = 'arm-none-eabi-'
    OBJDUMP = (PREFIX + 'objdump')
    NM = (PREFIX + 'nm')
    AS = (PREFIX + 'as')

OUTPUT = 'build/output.bin'
OUTPUT_FIELD = 'build/output_field.bin'
OUTPUT_BATTLE = 'build/output_battle.bin'
BYTE_REPLACEMENT = 'buildsys/bytereplacement'
HOOKS = 'buildsys/hooks'
ARM_HOOKS = 'buildsys/armhooks'
REPOINTS = 'buildsys/repoints'
ROUTINE_POINTERS = 'buildsys/routinepointers'

LINKED_SECTIONS = ['build/linked.o', 'build/battle_linked.o', 'build/field_linked.o']
OFFSET_START_IN_122 = 0x023D8000 + 0x1000
OFFSET_START = [0x023D8000, 0x023C0200, 0x023C0200]

def ExtractPointer(byteList: list[bytes]):
    pointer = 0
    for a in range(len(byteList)):
        pointer += (int(byteList[a])) << (8 * a)

    return pointer


def GetTextSection(section=0) -> int:
    #return 0
    try:
        # Dump sections
        out = subprocess.check_output([OBJDUMP, '-t', LINKED_SECTIONS[section]])
        lines = out.decode().split('\n')
    
        # Find text section
        text = filter(lambda x: x.strip().endswith('.text'), lines)
        section = (list(text))[0]
    
        # Get the offset
        offset = int(section.split(' ')[0], 16)
        return offset
    
    except:
        print("Error: The insertion process could not be completed.\n"
              + "The linker symbol file was not found. Most likely the compilation process was not completed.")
        sys.exit(1)


def GetSymbols() -> dict[str, int]:
    ret = {}

    for section in LINKED_SECTIONS:
        #subtract = GetTextSection(section)
        out = subprocess.check_output([NM, section])
        lines = out.decode().split('\n')

        for line in lines:
            parts = line.strip().split()

            if len(parts) < 3:
                continue

            if parts[1].lower() not in {'t', 'd'}:
                continue
    
            offset = int(parts[0], 16)
            ret[parts[2]] = offset# - subtract

    return ret


def Hook(rom: _io.BufferedReader, space: int, hookAt: int, register=0):
    # Align 2
    if hookAt & 1:
        hookAt -= 1

    rom.seek(hookAt)

    if (register > 7):
        print("Register used to hook at " + str(space) + " is > 7 (r" + str(register) + " used).  Modulo'd by 8.")
    register &= 7

    if hookAt % 4:
        data = bytes([0x01, 0x48 | register, 0x00 | (register << 3), 0x47, 0x0, 0x0])
    else:
        data = bytes([0x00, 0x48 | register, 0x00 | (register << 3), 0x47])

    #space += OFFSET_START + 1
    space += 1
    data += (space.to_bytes(4, 'little'))
    rom.write(bytes(data))


def HookARM(rom: _io.BufferedReader, space: int, hookAt: int, register=0):
    # Align 4
    if hookAt & 3:
        hookAt -= hookAt % 4

    rom.seek(hookAt)

    if (register > 12):
        print("Register used to hook at " + str(space) + " is > 12 (r" + str(register) + " used).  Results may be unstable.")

    data = bytes([0x00, 0x00 | register << 4, 0x9F, 0xE5, 0x10 | register, 0xFF, 0x2F, 0xE1])

    #space += OFFSET_START + 1
    #space += 1 # no thumb bit here
    data += (space.to_bytes(4, 'little'))
    rom.write(bytes(data))


def Repoint(rom: _io.BufferedReader, space: int, repointAt: int, slideFactor=0):
    rom.seek(repointAt)

    #space += (OFFSET_START + slideFactor)
    space += (slideFactor)
    data = (space.to_bytes(4, 'little'))
    rom.write(bytes(data))


def ReplaceBytes(rom: _io.BufferedReader, offset: int, data: str):
    ar = offset
    words = data.split()
    for i in range(0, len(words)):
        rom.seek(ar)
        intByte = int(words[i], 16)
        rom.write(bytes(intByte.to_bytes(1, 'big')))
        ar += 1


def TryProcessFileInclusion(line: str, definesDict: dict) -> bool:
    if line.startswith('#include "'):
        try:
            path = line.split('"')[1].strip()
            with open(path, 'r', encoding="UTF-8") as file:
                for line in file:
                    if line.startswith('#define '):
                        try:
                            lineList = line.strip().split()
                            title = lineList[1]

                            if len(lineList) == 2 or lineList[2].startswith('//') or lineList[2].startswith('/*'):
                                define = True
                            else:
                                define = lineList[2]

                            definesDict[title] = define
                        except IndexError:
                            print('Error reading define on line"' + line.strip() + '" in file "' + path + '".')

        except Exception as e:
            print('Error including file on line "' + line.strip() + '".')
            print(e)

        return True  # Inclusion line; don't read otherwise

    return False


def TryProcessConditionalCompilation(line: str, definesDict: dict, conditionals: list[tuple[str, bool]]) -> bool:
    line = line.strip()
    upperLine = line.upper()
    numWordsOnLine = len(line.split())

    if upperLine.startswith('#IFDEF ') and numWordsOnLine > 1:
        condition = line.strip().split()[1]
        conditionals.insert(0, (condition, True))  # Insert at front
        return True
    elif upperLine.startswith('#IFNDEF ') and numWordsOnLine > 1:
        condition = line.strip().split()[1]
        conditionals.insert(0, (condition, False))  # Insert at front
        return True
    elif upperLine == '#ELSE':
        if len(conditionals) >= 1:  # At least one statement was pushed before
            condition = conditionals.pop(0)
            if condition[1] is True:
                conditionals.insert(0, (condition[0], False))  # Invert old statement
            else:
                conditionals.insert(0, (condition[0], True))  # Invert old statement
            return True
    elif upperLine == '#ENDIF':
        conditionals.pop(0)  # Remove first element (last pushed)
        return True
    else:
        for condition in conditionals:
            definedType = condition[1]
            condition = condition[0]

            if definedType is True:  # From #ifdef
                if condition not in definesDict:
                    return True  # If something isn't defined then skip the line
            else:  # From #ifndef
                if condition in definesDict:
                    return True  # If something is defined then skip the line

    return False


def install():
    if os.path.isfile(BYTE_REPLACEMENT):
        with open(BYTE_REPLACEMENT, 'r') as replacelist:
            definesDict = {}
            conditionals = []
            for line in replacelist:
                if TryProcessFileInclusion(line, definesDict):
                    continue
                if TryProcessConditionalCompilation(line, definesDict, conditionals):
                    continue
                if line.strip().startswith('#') or line.strip() == '':
                    continue

                #offset = int(line[4:13], 16) - 0x08000000
                openbin = line[:4]
                if openbin == "arm9":
                    rom2 = open("base/arm9.bin", 'rb+')
                    offset = int(line[4:13], 16) - 0x02000000 if int(line[4:13], 16) & 0x02000000 else int(line[4:13], 16) - 0x08000000
                else:
                    rom2 = open("base/overlay/overlay_" + openbin + ".bin", 'rb+')
                    with open("base/y9.bin", 'rb+') as y9Table:
                        y9Table.seek((int(openbin)*0x20)+0x4) # read the overlay memory address for offset calculation
                        offset = int(line[4:13], 16) - struct.unpack_from("<I", y9Table.read(4))[0] if int(line[4:13], 16) & 0x02000000 else int(line[4:13], 16) - 0x08000000
                try:
                    ReplaceBytes(rom2, offset, line[13:].strip())
                except ValueError:  # Try loading from the defines dict if unrecognizable character
                    newNumber = definesDict[line[13:].strip()]
                    try:
                        newNumber = int(newNumber)
                    except ValueError:
                        newNumber = int(newNumber, 16)

                    newNumber = str(hex(newNumber)).split('0x')[1]
                    ReplaceBytes(rom2, offset, newNumber)
                rom2.close()


def _hook(file_name: str, hook_func: typing.Callable, register_override: bool=False, try_offset: bool=False):
    if os.path.isfile(file_name):
        table = GetSymbols()
        with open(file_name, 'r') as hookList:
            definesDict = {}
            conditionals = []
            for line in hookList:
                if TryProcessFileInclusion(line, definesDict):
                    continue
                if TryProcessConditionalCompilation(line, definesDict, conditionals):
                    continue
                if line.strip().startswith('#') or line.strip() == '':
                    continue

                if register_override:
                    files, symbol, address = line.split()
                else:
                    files, symbol, address, register = line.split()

                try:
                    if try_offset:
                        register = 0
                        if '+' in symbol:
                            symbol, add_offset_str = symbol.split('+')
                            register = int(add_offset_str, 16)
                    code = table[symbol]
                except KeyError:
                    print('Symbol missing:', symbol)
                    continue
                if files == "arm9":
                    rom2 = open("base/arm9.bin", 'rb+')
                    offset = int(address, 16) - 0x02000000 if int(address, 16) & 0x02000000 else int(address, 16) - 0x08000000
                else:
                    rom2 = open("base/overlay/overlay_" + files + ".bin", 'rb+')
                    with open("base/y9.bin", 'rb+') as y9Table:
                        y9Table.seek((int(files)*0x20)+0x4) # read the overlay memory address for offset calculation
                        offset = int(address, 16) - struct.unpack_from("<I", y9Table.read(4))[0] if int(address, 16) & 0x02000000 else int(address, 16) - 0x08000000
                hook_func(rom2, code, offset, int(register))
                rom2.close()


def hook():
    _hook(HOOKS, Hook)
    _hook(ARM_HOOKS, HookARM)


def _write(offects_file: str, binary_file: str, offset: int=0):
    with open(offects_file, 'wb+') as rom:
        print(f'Inserting code to {offects_file}.')
        table = GetSymbols()
        with open(binary_file, 'rb') as binary:
            rom.seek(offset)
            rom.write(binary.read())
            binary.close()
        rom.close()
    return table


def writeall():
    table = _write("base/overlay/overlay_0122.bin", OUTPUT, OFFSET_START_IN_122 - OFFSET_START[0])
    table = _write("base/overlay/overlay_0123.bin", OUTPUT_BATTLE)
    table = _write("base/overlay/overlay_0124.bin", OUTPUT_FIELD)

    width = max(map(len, table.keys())) + 1
    if os.path.isfile('offsets.ini'):
        offsetIni = open('offsets.ini', 'r+')
    else:
        offsetIni = open('offsets.ini', 'w')

    offsetIni.truncate()
    for key in sorted(table.keys()):
        fstr = ('{:' + str(width) + '} {:08X}')
        offsetIni.write(fstr.format(key + ':', table[key]) + '\n')
    offsetIni.close()


def repoint():
    _hook(ROUTINE_POINTERS, Repoint, register_override=True)


def offset():
    _hook(REPOINTS, Repoint, try_offset=True)


if __name__ == '__main__':
    writeall()
    install()
    hook()
    repoint()
    offset()
