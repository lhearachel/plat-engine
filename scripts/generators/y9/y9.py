y9 = open('../../../base/y9.bin', 'rb')

for _ in range(122):
    entry = y9.read(32)
    ov_num     = int.from_bytes(entry[0x00:0x04], 'little')
    ram_adrs   = int.from_bytes(entry[0x04:0x08], 'little')
    ram_size   = int.from_bytes(entry[0x08:0x0C], 'little') # not used in output
    bss_size   = int.from_bytes(entry[0x0C:0x10], 'little')
    init_start = int.from_bytes(entry[0x10:0x14], 'little')
    init_end   = int.from_bytes(entry[0x14:0x18], 'little')
    file_id    = int.from_bytes(entry[0x18:0x1C], 'little') # should always be identical to ov_num
    reserved   = int.from_bytes(entry[0x1C:0x20], 'little') # always 0

    print(f'/* overlay {str(ov_num).rjust(3, " ")} */ // .word {str(ov_num).rjust(3, " ")}, 0x{ram_adrs:08X}, filesize("base/overlay/overlay_{str(ov_num).rjust(4, "0")}.bin"), 0x{bss_size:08X}, 0x{init_start:08X}, 0x{init_end:08X}, {str(ov_num).rjust(3, " ")}, 0')

y9.close()
