.nds

.open "base/y9.bin", 0

// Based off of the overlay table defined in JimB16/PokePlat
//
// https://github.com/JimB16/PokePlat/blob/master/source/y9.s
//
// And also off of the overlay data definitions in pret/pokeplatinum
//
// https://github.com/pret/pokeplatinum
//
// ARM9 overlay table definition
//
// Addr  Size  Expl.
//  00h     4  Overlay ID
//  04h     4  RAM Address (point at which to load)
//  08h     4  RAM Size    (amount to load)
//  0Ch     4  BSS Size    (size of BSS data region)
//  10h     4  Static initializer start address
//  14h     4  Static initializer end address
//  18h     4  File ID     (0000h..EFFFh)
//  1Ch     4  Reserved 0  (in HG, this is compressed/uncompressed)

// Generated from vanilla Platinum (US, Rev1)'s y9.bin using scripts/generators/y9/y9.py
/* overlay   0 */ // .word   0, 0x021D0D80, filesize("base/overlay/overlay_0000.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   0, 0
/* overlay   1 */ // .word   1, 0x021D0D80, filesize("base/overlay/overlay_0001.bin"), 0x00000020, 0x021D0D90, 0x021D0D98,   1, 0
/* overlay   2 */ // .word   2, 0x021D0DC0, filesize("base/overlay/overlay_0002.bin"), 0x00000000, 0x021D0DC0, 0x021D0DC4,   2, 0
/* overlay   3 */ // .word   3, 0x01FF8660, filesize("base/overlay/overlay_0003.bin"), 0x00000000, 0x01FF8660, 0x01FF8664,   3, 0
/* overlay   4 */ // .word   4, 0x021D0D80, filesize("base/overlay/overlay_0004.bin"), 0x00005400, 0x02215E70, 0x02215E74,   4, 0
/* overlay   5 */ // .word   5, 0x021D0D80, filesize("base/overlay/overlay_0005.bin"), 0x0003C020, 0x02201D18, 0x02201D1C,   5, 0
/* overlay   6 */ // .word   6, 0x0223E140, filesize("base/overlay/overlay_0006.bin"), 0x00000020, 0x02249858, 0x0224985C,   6, 0
/* overlay   7 */ // .word   7, 0x02249960, filesize("base/overlay/overlay_0007.bin"), 0x00000020, 0x0224F4A8, 0x0224F4AC,   7, 0
/* overlay   8 */ // .word   8, 0x02249960, filesize("base/overlay/overlay_0008.bin"), 0x00000000, 0x0224E73C, 0x0224E740,   8, 0
/* overlay   9 */ // .word   9, 0x02249960, filesize("base/overlay/overlay_0009.bin"), 0x00000000, 0x02253AF0, 0x02253AF4,   9, 0
/* overlay  10 */ // .word  10, 0x0221F800, filesize("base/overlay/overlay_0010.bin"), 0x00000000, 0x02223284, 0x02223288,  10, 0
/* overlay  11 */ // .word  11, 0x0221F800, filesize("base/overlay/overlay_0011.bin"), 0x00000000, 0x0221FC18, 0x0221FC1C,  11, 0
/* overlay  12 */ // .word  12, 0x0221FC20, filesize("base/overlay/overlay_0012.bin"), 0x00000000, 0x0223B100, 0x0223B104,  12, 0
/* overlay  13 */ // .word  13, 0x0221FC20, filesize("base/overlay/overlay_0013.bin"), 0x00000000, 0x02229E1C, 0x02229E20,  13, 0
/* overlay  14 */ // .word  14, 0x0221FC20, filesize("base/overlay/overlay_0014.bin"), 0x00000000, 0x0222F060, 0x0222F064,  14, 0
/* overlay  15 */ // .word  15, 0x021D0D80, filesize("base/overlay/overlay_0015.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  15, 0
/* overlay  16 */ // .word  16, 0x0223B140, filesize("base/overlay/overlay_0016.bin"), 0x00000000, 0x02270B0C, 0x02270B14,  16, 0
/* overlay  17 */ // .word  17, 0x0223B140, filesize("base/overlay/overlay_0017.bin"), 0x00000000, 0x02254DD0, 0x02254DD8,  17, 0
/* overlay  18 */ // .word  18, 0x0221F800, filesize("base/overlay/overlay_0018.bin"), 0x000081E0, 0x02249740, 0x02249744,  18, 0
/* overlay  19 */ // .word  19, 0x021D0D80, filesize("base/overlay/overlay_0019.bin"), 0x000001A0, 0x021E05AC, 0x021E05B0,  19, 0
/* overlay  20 */ // .word  20, 0x021D0D80, filesize("base/overlay/overlay_0020.bin"), 0x00000000, 0x021D5430, 0x021D5434,  20, 0
/* overlay  21 */ // .word  21, 0x021D0D80, filesize("base/overlay/overlay_0021.bin"), 0x00000000, 0x021E9F68, 0x021E9F6C,  21, 0
/* overlay  22 */ // .word  22, 0x02254DE0, filesize("base/overlay/overlay_0022.bin"), 0x00000000, 0x0225BE78, 0x0225BE7C,  22, 0
/* overlay  23 */ // .word  23, 0x0223E140, filesize("base/overlay/overlay_0023.bin"), 0x00000080, 0x02256BC4, 0x02256BC8,  23, 0
/* overlay  24 */ // .word  24, 0x02253CE0, filesize("base/overlay/overlay_0024.bin"), 0x00000000, 0x02253DD4, 0x02253DD8,  24, 0
/* overlay  25 */ // .word  25, 0x02253CE0, filesize("base/overlay/overlay_0025.bin"), 0x00000000, 0x022561A4, 0x022561A8,  25, 0
/* overlay  26 */ // .word  26, 0x022561C0, filesize("base/overlay/overlay_0026.bin"), 0x00000000, 0x02256780, 0x02256788,  26, 0
/* overlay  27 */ // .word  27, 0x022561C0, filesize("base/overlay/overlay_0027.bin"), 0x00000000, 0x022570B0, 0x022570B8,  27, 0
/* overlay  28 */ // .word  28, 0x022561C0, filesize("base/overlay/overlay_0028.bin"), 0x00000000, 0x02257AA8, 0x02257AB0,  28, 0
/* overlay  29 */ // .word  29, 0x022561C0, filesize("base/overlay/overlay_0029.bin"), 0x00000000, 0x02256C04, 0x02256C0C,  29, 0
/* overlay  30 */ // .word  30, 0x022561C0, filesize("base/overlay/overlay_0030.bin"), 0x00000000, 0x02256700, 0x02256708,  30, 0
/* overlay  31 */ // .word  31, 0x022561C0, filesize("base/overlay/overlay_0031.bin"), 0x00000000, 0x022569A0, 0x022569A8,  31, 0
/* overlay  32 */ // .word  32, 0x022561C0, filesize("base/overlay/overlay_0032.bin"), 0x00000000, 0x02256D48, 0x02256D50,  32, 0
/* overlay  33 */ // .word  33, 0x022561C0, filesize("base/overlay/overlay_0033.bin"), 0x00000000, 0x0225789C, 0x022578A4,  33, 0
/* overlay  34 */ // .word  34, 0x022561C0, filesize("base/overlay/overlay_0034.bin"), 0x00000000, 0x02256AAC, 0x02256AB4,  34, 0
/* overlay  35 */ // .word  35, 0x022561C0, filesize("base/overlay/overlay_0035.bin"), 0x00000000, 0x022567A8, 0x022567B0,  35, 0
/* overlay  36 */ // .word  36, 0x022561C0, filesize("base/overlay/overlay_0036.bin"), 0x00000000, 0x022567A0, 0x022567A8,  36, 0
/* overlay  37 */ // .word  37, 0x022561C0, filesize("base/overlay/overlay_0037.bin"), 0x00000000, 0x02256644, 0x0225664C,  37, 0
/* overlay  38 */ // .word  38, 0x022561C0, filesize("base/overlay/overlay_0038.bin"), 0x00000000, 0x022564C0, 0x022564C8,  38, 0
/* overlay  39 */ // .word  39, 0x022561C0, filesize("base/overlay/overlay_0039.bin"), 0x00000000, 0x02256678, 0x02256680,  39, 0
/* overlay  40 */ // .word  40, 0x022561C0, filesize("base/overlay/overlay_0040.bin"), 0x00000000, 0x02256B40, 0x02256B48,  40, 0
/* overlay  41 */ // .word  41, 0x022561C0, filesize("base/overlay/overlay_0041.bin"), 0x00000000, 0x02256E78, 0x02256E80,  41, 0
/* overlay  42 */ // .word  42, 0x022561C0, filesize("base/overlay/overlay_0042.bin"), 0x00000020, 0x02256710, 0x02256718,  42, 0
/* overlay  43 */ // .word  43, 0x022561C0, filesize("base/overlay/overlay_0043.bin"), 0x00000000, 0x02256CDC, 0x02256CE4,  43, 0
/* overlay  44 */ // .word  44, 0x022561C0, filesize("base/overlay/overlay_0044.bin"), 0x00000000, 0x02256E98, 0x02256EA0,  44, 0
/* overlay  45 */ // .word  45, 0x022561C0, filesize("base/overlay/overlay_0045.bin"), 0x00000000, 0x02256E04, 0x02256E0C,  45, 0
/* overlay  46 */ // .word  46, 0x022561C0, filesize("base/overlay/overlay_0046.bin"), 0x00000000, 0x022572F4, 0x022572FC,  46, 0
/* overlay  47 */ // .word  47, 0x022561C0, filesize("base/overlay/overlay_0047.bin"), 0x00000000, 0x02256A9C, 0x02256AA4,  47, 0
/* overlay  48 */ // .word  48, 0x022561C0, filesize("base/overlay/overlay_0048.bin"), 0x00000000, 0x02256B70, 0x02256B78,  48, 0
/* overlay  49 */ // .word  49, 0x022561C0, filesize("base/overlay/overlay_0049.bin"), 0x00000000, 0x0225663C, 0x02256644,  49, 0
/* overlay  50 */ // .word  50, 0x022561C0, filesize("base/overlay/overlay_0050.bin"), 0x00000000, 0x02256AF0, 0x02256AF8,  50, 0
/* overlay  51 */ // .word  51, 0x022561C0, filesize("base/overlay/overlay_0051.bin"), 0x00000000, 0x022564C0, 0x022564C8,  51, 0
/* overlay  52 */ // .word  52, 0x022561C0, filesize("base/overlay/overlay_0052.bin"), 0x00000000, 0x02256E50, 0x02256E58,  52, 0
/* overlay  53 */ // .word  53, 0x022561C0, filesize("base/overlay/overlay_0053.bin"), 0x00000000, 0x02256A50, 0x02256A58,  53, 0
/* overlay  54 */ // .word  54, 0x022561C0, filesize("base/overlay/overlay_0054.bin"), 0x00000000, 0x02256810, 0x02256818,  54, 0
/* overlay  55 */ // .word  55, 0x022561C0, filesize("base/overlay/overlay_0055.bin"), 0x00000000, 0x022564D0, 0x022564D8,  55, 0
/* overlay  56 */ // .word  56, 0x022561C0, filesize("base/overlay/overlay_0056.bin"), 0x00000000, 0x022572F0, 0x022572F4,  56, 0
/* overlay  57 */ // .word  57, 0x021D0D80, filesize("base/overlay/overlay_0057.bin"), 0x00000000, 0x021D1178, 0x021D117C,  57, 0
/* overlay  58 */ // .word  58, 0x021D0D80, filesize("base/overlay/overlay_0058.bin"), 0x00000000, 0x021D3174, 0x021D3178,  58, 0
/* overlay  59 */ // .word  59, 0x021D0D80, filesize("base/overlay/overlay_0059.bin"), 0x00000000, 0x021D3474, 0x021D3478,  59, 0
/* overlay  60 */ // .word  60, 0x0221F800, filesize("base/overlay/overlay_0060.bin"), 0x00001040, 0x02228E24, 0x02228E28,  60, 0
/* overlay  61 */ // .word  61, 0x0222AE60, filesize("base/overlay/overlay_0061.bin"), 0x00000B60, 0x0222E5E0, 0x0222E5E4,  61, 0
/* overlay  62 */ // .word  62, 0x0222F2C0, filesize("base/overlay/overlay_0062.bin"), 0x00000000, 0x022497A0, 0x022497A4,  62, 0
/* overlay  63 */ // .word  63, 0x0222AE60, filesize("base/overlay/overlay_0063.bin"), 0x00000000, 0x0222DCD0, 0x0222DCD4,  63, 0
/* overlay  64 */ // .word  64, 0x0222DCE0, filesize("base/overlay/overlay_0064.bin"), 0x00000000, 0x0223243C, 0x02232440,  64, 0
/* overlay  65 */ // .word  65, 0x0222DCE0, filesize("base/overlay/overlay_0065.bin"), 0x00000020, 0x02239C18, 0x02239C1C,  65, 0
/* overlay  66 */ // .word  66, 0x0222DCE0, filesize("base/overlay/overlay_0066.bin"), 0x00001040, 0x02258D08, 0x02258D0C,  66, 0
/* overlay  67 */ // .word  67, 0x0225C700, filesize("base/overlay/overlay_0067.bin"), 0x00000000, 0x0225D48C, 0x0225D490,  67, 0
/* overlay  68 */ // .word  68, 0x0225C700, filesize("base/overlay/overlay_0068.bin"), 0x00000000, 0x0225DE88, 0x0225DE8C,  68, 0
/* overlay  69 */ // .word  69, 0x0225C700, filesize("base/overlay/overlay_0069.bin"), 0x00000000, 0x0225F420, 0x0225F424,  69, 0
/* overlay  70 */ // .word  70, 0x0225C700, filesize("base/overlay/overlay_0070.bin"), 0x00000000, 0x0226E7B0, 0x0226E7B4,  70, 0
/* overlay  71 */ // .word  71, 0x0223B140, filesize("base/overlay/overlay_0071.bin"), 0x00000000, 0x0223D78C, 0x0223D790,  71, 0
/* overlay  72 */ // .word  72, 0x0223D7A0, filesize("base/overlay/overlay_0072.bin"), 0x00000000, 0x0223ED30, 0x0223ED34,  72, 0
/* overlay  73 */ // .word  73, 0x021D0D80, filesize("base/overlay/overlay_0073.bin"), 0x00000000, 0x021D3AE8, 0x021D3AEC,  73, 0
/* overlay  74 */ // .word  74, 0x021D0D80, filesize("base/overlay/overlay_0074.bin"), 0x00000000, 0x021D1D10, 0x021D1D14,  74, 0
/* overlay  75 */ // .word  75, 0x021D0D80, filesize("base/overlay/overlay_0075.bin"), 0x00000000, 0x021D1E24, 0x021D1E28,  75, 0
/* overlay  76 */ // .word  76, 0x0223B140, filesize("base/overlay/overlay_0076.bin"), 0x00000000, 0x0223EF64, 0x0223EF6C,  76, 0
/* overlay  77 */ // .word  77, 0x021D0D80, filesize("base/overlay/overlay_0077.bin"), 0x00000000, 0x021D7994, 0x021D7998,  77, 0
/* overlay  78 */ // .word  78, 0x021D0D80, filesize("base/overlay/overlay_0078.bin"), 0x00000000, 0x021D29E8, 0x021D29EC,  78, 0
/* overlay  79 */ // .word  79, 0x021D0D80, filesize("base/overlay/overlay_0079.bin"), 0x00000000, 0x021D3CF8, 0x021D3CFC,  79, 0
/* overlay  80 */ // .word  80, 0x021D0D80, filesize("base/overlay/overlay_0080.bin"), 0x00000000, 0x021D3368, 0x021D336C,  80, 0
/* overlay  81 */ // .word  81, 0x021D0D80, filesize("base/overlay/overlay_0081.bin"), 0x00000000, 0x021D3528, 0x021D352C,  81, 0
/* overlay  82 */ // .word  82, 0x0223B140, filesize("base/overlay/overlay_0082.bin"), 0x00000000, 0x0223B584, 0x0223B588,  82, 0
/* overlay  83 */ // .word  83, 0x0223B5A0, filesize("base/overlay/overlay_0083.bin"), 0x00000000, 0x022405A4, 0x022405A8,  83, 0
/* overlay  84 */ // .word  84, 0x0223B5A0, filesize("base/overlay/overlay_0084.bin"), 0x00000000, 0x02241420, 0x02241424,  84, 0
/* overlay  85 */ // .word  85, 0x02241440, filesize("base/overlay/overlay_0085.bin"), 0x00000000, 0x02242A58, 0x02242A5C,  85, 0
/* overlay  86 */ // .word  86, 0x0223B140, filesize("base/overlay/overlay_0086.bin"), 0x00000020, 0x0223D520, 0x0223D524,  86, 0
/* overlay  87 */ // .word  87, 0x021D0D80, filesize("base/overlay/overlay_0087.bin"), 0x00000000, 0x021D1B88, 0x021D1B8C,  87, 0
/* overlay  88 */ // .word  88, 0x0223B140, filesize("base/overlay/overlay_0088.bin"), 0x00000000, 0x0223F1F8, 0x0223F1FC,  88, 0
/* overlay  89 */ // .word  89, 0x021D0D80, filesize("base/overlay/overlay_0089.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  89, 0
/* overlay  90 */ // .word  90, 0x021D0D80, filesize("base/overlay/overlay_0090.bin"), 0x00000000, 0x021D1F20, 0x021D1F24,  90, 0
/* overlay  91 */ // .word  91, 0x021D0D80, filesize("base/overlay/overlay_0091.bin"), 0x00000000, 0x021D2BA0, 0x021D2BA4,  91, 0
/* overlay  92 */ // .word  92, 0x021D0D80, filesize("base/overlay/overlay_0092.bin"), 0x00000000, 0x021D2AA0, 0x021D2AA4,  92, 0
/* overlay  93 */ // .word  93, 0x021D0D80, filesize("base/overlay/overlay_0093.bin"), 0x00000000, 0x021D1594, 0x021D1598,  93, 0
/* overlay  94 */ // .word  94, 0x0223B140, filesize("base/overlay/overlay_0094.bin"), 0x00000160, 0x022463E8, 0x022463EC,  94, 0
/* overlay  95 */ // .word  95, 0x02246C20, filesize("base/overlay/overlay_0095.bin"), 0x000000A0, 0x0224C2A4, 0x0224C2A8,  95, 0
/* overlay  96 */ // .word  96, 0x0223B140, filesize("base/overlay/overlay_0096.bin"), 0x00000120, 0x0223DB40, 0x0223DB44,  96, 0
/* overlay  97 */ // .word  97, 0x0222AE60, filesize("base/overlay/overlay_0097.bin"), 0x00001980, 0x0223DF38, 0x0223DF3C,  97, 0
/* overlay  98 */ // .word  98, 0x02246C20, filesize("base/overlay/overlay_0098.bin"), 0x00000020, 0x02249D54, 0x02249D58,  98, 0
/* overlay  99 */ // .word  99, 0x021D0D80, filesize("base/overlay/overlay_0099.bin"), 0x00000000, 0x021D54DC, 0x021D54E0,  99, 0
/* overlay 100 */ // .word 100, 0x021D0D80, filesize("base/overlay/overlay_0100.bin"), 0x00000000, 0x021D5490, 0x021D5494, 100, 0
/* overlay 101 */ // .word 101, 0x021D0D80, filesize("base/overlay/overlay_0101.bin"), 0x00000000, 0x021D9E44, 0x021D9E48, 101, 0
/* overlay 102 */ // .word 102, 0x021D0D80, filesize("base/overlay/overlay_0102.bin"), 0x00000000, 0x021D1584, 0x021D1588, 102, 0
/* overlay 103 */ // .word 103, 0x0222DCE0, filesize("base/overlay/overlay_0103.bin"), 0x00000000, 0x0222DCE0, 0x0222DCE4, 103, 0
/* overlay 104 */ // .word 104, 0x0222DCE0, filesize("base/overlay/overlay_0104.bin"), 0x00000020, 0x02241990, 0x02241994, 104, 0
/* overlay 105 */ // .word 105, 0x02241AE0, filesize("base/overlay/overlay_0105.bin"), 0x00000000, 0x022464A8, 0x022464AC, 105, 0
/* overlay 106 */ // .word 106, 0x02241AE0, filesize("base/overlay/overlay_0106.bin"), 0x00000000, 0x02243880, 0x02243884, 106, 0
/* overlay 107 */ // .word 107, 0x02241AE0, filesize("base/overlay/overlay_0107.bin"), 0x00000000, 0x0224A318, 0x0224A31C, 107, 0
/* overlay 108 */ // .word 108, 0x02241AE0, filesize("base/overlay/overlay_0108.bin"), 0x00000020, 0x02243784, 0x02243788, 108, 0
/* overlay 109 */ // .word 109, 0x021D0D80, filesize("base/overlay/overlay_0109.bin"), 0x00000000, 0x021D5F1C, 0x021D5F20, 109, 0
/* overlay 110 */ // .word 110, 0x021D0D80, filesize("base/overlay/overlay_0110.bin"), 0x00000000, 0x021D2320, 0x021D2324, 110, 0
/* overlay 111 */ // .word 111, 0x021D0D80, filesize("base/overlay/overlay_0111.bin"), 0x00000000, 0x021D3938, 0x021D393C, 111, 0
/* overlay 112 */ // .word 112, 0x0225C700, filesize("base/overlay/overlay_0112.bin"), 0x00000000, 0x0225D94C, 0x0225D950, 112, 0
/* overlay 113 */ // .word 113, 0x0225C700, filesize("base/overlay/overlay_0113.bin"), 0x00000000, 0x02261560, 0x02261564, 113, 0
/* overlay 114 */ // .word 114, 0x0225C700, filesize("base/overlay/overlay_0114.bin"), 0x00000000, 0x02260420, 0x02260424, 114, 0
/* overlay 115 */ // .word 115, 0x02260440, filesize("base/overlay/overlay_0115.bin"), 0x00000040, 0x022666AC, 0x022666B0, 115, 0
/* overlay 116 */ // .word 116, 0x02260440, filesize("base/overlay/overlay_0116.bin"), 0x00000000, 0x02267F0C, 0x02267F10, 116, 0
/* overlay 117 */ // .word 117, 0x02260440, filesize("base/overlay/overlay_0117.bin"), 0x00000000, 0x02267034, 0x02267038, 117, 0
/* overlay 118 */ // .word 118, 0x021D0D80, filesize("base/overlay/overlay_0118.bin"), 0x00000000, 0x021D11A0, 0x021D11A4, 118, 0
/* overlay 119 */ // .word 119, 0x021D0D80, filesize("base/overlay/overlay_0119.bin"), 0x00000000, 0x021D26B4, 0x021D26B8, 119, 0
/* overlay 120 */ // .word 120, 0x021D0D80, filesize("base/overlay/overlay_0120.bin"), 0x00000000, 0x021D1238, 0x021D123C, 120, 0
/* overlay 121 */ // .word 121, 0x021D0D80, filesize("base/overlay/overlay_0121.bin"), 0x00000000, 0x021D13A8, 0x021D13AC, 121, 0

.org 122 * 0x20 // jump to new overlays

.word 122, 0x023C8000, filesize("base/overlay/overlay_0122.bin"), 0x00000000, 0x023C8000, 0x023C8000, 122, 0    // arm9 expansion
//.word 123, 0x023D0000, filesize("base/overlay/overlay_0123.bin"), 0x00000000, 0x023D0000, 0x023D0000, 123, 0    // battle overlay
//.word 124, 0x023D0000, filesize("base/overlay/overlay_0124.bin"), 0x00000000, 0x023D0000, 0x023D0000, 124, 0    // field overlay
