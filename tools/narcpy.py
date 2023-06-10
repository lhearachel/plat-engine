import sys
import os
import struct
import ndspy.narc


def format_int(val, narc_len):
    length = len(str(val))
    return '0'*(len(str(narc_len-1))-length) + str(val)


def extract(filename: str, extract: bool, path: str):
    narc = ndspy.narc.NARC.fromFile(filename)
    if extract:
        if not os.path.isdir(path):
            os.makedirs(path)
        for idx in range(len(narc.files)):
            name = os.path.join(path, '%s_%s' % (os.path.basename(filename), format_int(idx, len(narc.files))))
            data = narc.files[idx]
            with open(name, 'wb') as out:
                out.write(data)


def create(target: str, files_dir: str):
    files = []
    for v in range(len(os.listdir(files_dir))):
        files.append(None)

    idx = 0
    for entry in sorted(os.listdir(files_dir)):
        with open(os.path.join(files_dir, entry), 'rb') as f:
            files[idx] = f.read()
        idx += 1

    narc = ndspy.narc.NARC.fromFilesAndNames(files=files)
    narc.endiannessOfBeginning = '>'
    narc.saveToFile(target)

    narcfile = open(target, 'rb+')
    narcbytes = bytearray(narcfile.read())
    narcfile.close()
    
    FNTB_offset = narcbytes.find("BTNF".encode())
    
    #narcbytes[8] = narcbytes[8] - 4
    dataoffset = struct.unpack_from("<I", narcbytes[8:12])[0] - 4
    data = (dataoffset.to_bytes(4, 'little'))
    narcbytes[8:12] = data
    
    narcbytes[FNTB_offset+4] = 0x10;
    narcbytes[FNTB_offset+8] = 0x4;
    del narcbytes[FNTB_offset+0x10:FNTB_offset+0x14]
    
    narcfile = open(target, 'wb')
    narcfile.write(narcbytes)
    narcfile.close()


if __name__ == '__main__':
    args = sys.argv[1:]

    if args[0] == 'extract':
        extract(args[1], args[2] == '-o', args[3])
    elif args[0] == 'create':
        create(args[1], args[2])