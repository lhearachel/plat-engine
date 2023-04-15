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

// Generated from vanilla Platinum (US, Rev1)'s y9.bin
/* overlay   0 */ // .word   0, 0x021D0D80, filesize("base/overlay/overlay_0000.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   0, 0
/* overlay   1 */ // .word   1, 0x021D0D80, filesize("base/overlay/overlay_0001.bin"), 0x00000020, 0x021D0D80, 0x021D0D84,   1, 0
/* overlay   2 */ // .word   2, 0x021D0D80, filesize("base/overlay/overlay_0002.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   2, 0
/* overlay   3 */ // .word   3, 0x021D0D80, filesize("base/overlay/overlay_0003.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   3, 0
/* overlay   4 */ // .word   4, 0x021D0D80, filesize("base/overlay/overlay_0004.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   4, 0
/* overlay   5 */ // .word   5, 0x021D0D80, filesize("base/overlay/overlay_0005.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   5, 0
/* overlay   6 */ // .word   6, 0x021D0D80, filesize("base/overlay/overlay_0006.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   6, 0
/* overlay   7 */ // .word   7, 0x021D0D80, filesize("base/overlay/overlay_0007.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   7, 0
/* overlay   8 */ // .word   8, 0x021D0D80, filesize("base/overlay/overlay_0008.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   8, 0
/* overlay   9 */ // .word   9, 0x021D0D80, filesize("base/overlay/overlay_0009.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,   9, 0
/* overlay  10 */ // .word  10, 0x021D0D80, filesize("base/overlay/overlay_0010.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  10, 0
/* overlay  11 */ // .word  11, 0x021D0D80, filesize("base/overlay/overlay_0011.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  11, 0
/* overlay  12 */ // .word  12, 0x021D0D80, filesize("base/overlay/overlay_0012.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  12, 0
/* overlay  13 */ // .word  13, 0x021D0D80, filesize("base/overlay/overlay_0013.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  13, 0
/* overlay  14 */ // .word  14, 0x021D0D80, filesize("base/overlay/overlay_0014.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  14, 0
/* overlay  15 */ // .word  15, 0x021D0D80, filesize("base/overlay/overlay_0015.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  15, 0
/* overlay  16 */ // .word  16, 0x021D0D80, filesize("base/overlay/overlay_0016.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  16, 0
/* overlay  17 */ // .word  17, 0x021D0D80, filesize("base/overlay/overlay_0017.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  17, 0
/* overlay  18 */ // .word  18, 0x021D0D80, filesize("base/overlay/overlay_0018.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  18, 0
/* overlay  19 */ // .word  19, 0x021D0D80, filesize("base/overlay/overlay_0019.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  19, 0
/* overlay  20 */ // .word  20, 0x021D0D80, filesize("base/overlay/overlay_0020.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  20, 0
/* overlay  21 */ // .word  21, 0x021D0D80, filesize("base/overlay/overlay_0021.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  21, 0
/* overlay  22 */ // .word  22, 0x021D0D80, filesize("base/overlay/overlay_0022.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  22, 0
/* overlay  23 */ // .word  23, 0x021D0D80, filesize("base/overlay/overlay_0023.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  23, 0
/* overlay  24 */ // .word  24, 0x021D0D80, filesize("base/overlay/overlay_0024.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  24, 0
/* overlay  25 */ // .word  25, 0x021D0D80, filesize("base/overlay/overlay_0025.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  25, 0
/* overlay  26 */ // .word  26, 0x021D0D80, filesize("base/overlay/overlay_0026.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  26, 0
/* overlay  27 */ // .word  27, 0x021D0D80, filesize("base/overlay/overlay_0027.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  27, 0
/* overlay  28 */ // .word  28, 0x021D0D80, filesize("base/overlay/overlay_0028.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  28, 0
/* overlay  29 */ // .word  29, 0x021D0D80, filesize("base/overlay/overlay_0029.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  29, 0
/* overlay  30 */ // .word  30, 0x021D0D80, filesize("base/overlay/overlay_0030.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  30, 0
/* overlay  31 */ // .word  31, 0x021D0D80, filesize("base/overlay/overlay_0031.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  31, 0
/* overlay  32 */ // .word  32, 0x021D0D80, filesize("base/overlay/overlay_0032.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  32, 0
/* overlay  33 */ // .word  33, 0x021D0D80, filesize("base/overlay/overlay_0033.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  33, 0
/* overlay  34 */ // .word  34, 0x021D0D80, filesize("base/overlay/overlay_0034.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  34, 0
/* overlay  35 */ // .word  35, 0x021D0D80, filesize("base/overlay/overlay_0035.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  35, 0
/* overlay  36 */ // .word  36, 0x021D0D80, filesize("base/overlay/overlay_0036.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  36, 0
/* overlay  37 */ // .word  37, 0x021D0D80, filesize("base/overlay/overlay_0037.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  37, 0
/* overlay  38 */ // .word  38, 0x021D0D80, filesize("base/overlay/overlay_0038.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  38, 0
/* overlay  39 */ // .word  39, 0x021D0D80, filesize("base/overlay/overlay_0039.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  39, 0
/* overlay  40 */ // .word  40, 0x021D0D80, filesize("base/overlay/overlay_0040.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  40, 0
/* overlay  41 */ // .word  41, 0x021D0D80, filesize("base/overlay/overlay_0041.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  41, 0
/* overlay  42 */ // .word  42, 0x021D0D80, filesize("base/overlay/overlay_0042.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  42, 0
/* overlay  43 */ // .word  43, 0x021D0D80, filesize("base/overlay/overlay_0043.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  43, 0
/* overlay  44 */ // .word  44, 0x021D0D80, filesize("base/overlay/overlay_0044.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  44, 0
/* overlay  45 */ // .word  45, 0x021D0D80, filesize("base/overlay/overlay_0045.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  45, 0
/* overlay  46 */ // .word  46, 0x021D0D80, filesize("base/overlay/overlay_0046.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  46, 0
/* overlay  47 */ // .word  47, 0x021D0D80, filesize("base/overlay/overlay_0047.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  47, 0
/* overlay  48 */ // .word  48, 0x021D0D80, filesize("base/overlay/overlay_0048.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  48, 0
/* overlay  49 */ // .word  49, 0x021D0D80, filesize("base/overlay/overlay_0049.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  49, 0
/* overlay  50 */ // .word  50, 0x021D0D80, filesize("base/overlay/overlay_0050.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  50, 0
/* overlay  51 */ // .word  51, 0x021D0D80, filesize("base/overlay/overlay_0051.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  51, 0
/* overlay  52 */ // .word  52, 0x021D0D80, filesize("base/overlay/overlay_0052.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  52, 0
/* overlay  53 */ // .word  53, 0x021D0D80, filesize("base/overlay/overlay_0053.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  53, 0
/* overlay  54 */ // .word  54, 0x021D0D80, filesize("base/overlay/overlay_0054.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  54, 0
/* overlay  55 */ // .word  55, 0x021D0D80, filesize("base/overlay/overlay_0055.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  55, 0
/* overlay  56 */ // .word  56, 0x021D0D80, filesize("base/overlay/overlay_0056.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  56, 0
/* overlay  57 */ // .word  57, 0x021D0D80, filesize("base/overlay/overlay_0057.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  57, 0
/* overlay  58 */ // .word  58, 0x021D0D80, filesize("base/overlay/overlay_0058.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  58, 0
/* overlay  59 */ // .word  59, 0x021D0D80, filesize("base/overlay/overlay_0059.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  59, 0
/* overlay  60 */ // .word  60, 0x021D0D80, filesize("base/overlay/overlay_0060.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  60, 0
/* overlay  61 */ // .word  61, 0x021D0D80, filesize("base/overlay/overlay_0061.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  61, 0
/* overlay  62 */ // .word  62, 0x021D0D80, filesize("base/overlay/overlay_0062.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  62, 0
/* overlay  63 */ // .word  63, 0x021D0D80, filesize("base/overlay/overlay_0063.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  63, 0
/* overlay  64 */ // .word  64, 0x021D0D80, filesize("base/overlay/overlay_0064.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  64, 0
/* overlay  65 */ // .word  65, 0x021D0D80, filesize("base/overlay/overlay_0065.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  65, 0
/* overlay  66 */ // .word  66, 0x021D0D80, filesize("base/overlay/overlay_0066.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  66, 0
/* overlay  67 */ // .word  67, 0x021D0D80, filesize("base/overlay/overlay_0067.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  67, 0
/* overlay  68 */ // .word  68, 0x021D0D80, filesize("base/overlay/overlay_0068.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  68, 0
/* overlay  69 */ // .word  69, 0x021D0D80, filesize("base/overlay/overlay_0069.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  69, 0
/* overlay  70 */ // .word  70, 0x021D0D80, filesize("base/overlay/overlay_0070.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  70, 0
/* overlay  71 */ // .word  71, 0x021D0D80, filesize("base/overlay/overlay_0071.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  71, 0
/* overlay  72 */ // .word  72, 0x021D0D80, filesize("base/overlay/overlay_0072.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  72, 0
/* overlay  73 */ // .word  73, 0x021D0D80, filesize("base/overlay/overlay_0073.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  73, 0
/* overlay  74 */ // .word  74, 0x021D0D80, filesize("base/overlay/overlay_0074.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  74, 0
/* overlay  75 */ // .word  75, 0x021D0D80, filesize("base/overlay/overlay_0075.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  75, 0
/* overlay  76 */ // .word  76, 0x021D0D80, filesize("base/overlay/overlay_0076.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  76, 0
/* overlay  77 */ // .word  77, 0x021D0D80, filesize("base/overlay/overlay_0077.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  77, 0
/* overlay  78 */ // .word  78, 0x021D0D80, filesize("base/overlay/overlay_0078.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  78, 0
/* overlay  79 */ // .word  79, 0x021D0D80, filesize("base/overlay/overlay_0079.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  79, 0
/* overlay  80 */ // .word  80, 0x021D0D80, filesize("base/overlay/overlay_0080.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  80, 0
/* overlay  81 */ // .word  81, 0x021D0D80, filesize("base/overlay/overlay_0081.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  81, 0
/* overlay  82 */ // .word  82, 0x021D0D80, filesize("base/overlay/overlay_0082.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  82, 0
/* overlay  83 */ // .word  83, 0x021D0D80, filesize("base/overlay/overlay_0083.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  83, 0
/* overlay  84 */ // .word  84, 0x021D0D80, filesize("base/overlay/overlay_0084.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  84, 0
/* overlay  85 */ // .word  85, 0x021D0D80, filesize("base/overlay/overlay_0085.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  85, 0
/* overlay  86 */ // .word  86, 0x021D0D80, filesize("base/overlay/overlay_0086.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  86, 0
/* overlay  87 */ // .word  87, 0x021D0D80, filesize("base/overlay/overlay_0087.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  87, 0
/* overlay  88 */ // .word  88, 0x021D0D80, filesize("base/overlay/overlay_0088.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  88, 0
/* overlay  89 */ // .word  89, 0x021D0D80, filesize("base/overlay/overlay_0089.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  89, 0
/* overlay  90 */ // .word  90, 0x021D0D80, filesize("base/overlay/overlay_0090.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  90, 0
/* overlay  91 */ // .word  91, 0x021D0D80, filesize("base/overlay/overlay_0091.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  91, 0
/* overlay  92 */ // .word  92, 0x021D0D80, filesize("base/overlay/overlay_0092.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  92, 0
/* overlay  93 */ // .word  93, 0x021D0D80, filesize("base/overlay/overlay_0093.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  93, 0
/* overlay  94 */ // .word  94, 0x021D0D80, filesize("base/overlay/overlay_0094.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  94, 0
/* overlay  95 */ // .word  95, 0x021D0D80, filesize("base/overlay/overlay_0095.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  95, 0
/* overlay  96 */ // .word  96, 0x021D0D80, filesize("base/overlay/overlay_0096.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  96, 0
/* overlay  97 */ // .word  97, 0x021D0D80, filesize("base/overlay/overlay_0097.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  97, 0
/* overlay  98 */ // .word  98, 0x021D0D80, filesize("base/overlay/overlay_0098.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  98, 0
/* overlay  99 */ // .word  99, 0x021D0D80, filesize("base/overlay/overlay_0099.bin"), 0x00000000, 0x021D0D80, 0x021D0D84,  99, 0
/* overlay 100 */ // .word 100, 0x021D0D80, filesize("base/overlay/overlay_0100.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 100, 0
/* overlay 101 */ // .word 101, 0x021D0D80, filesize("base/overlay/overlay_0101.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 101, 0
/* overlay 102 */ // .word 102, 0x021D0D80, filesize("base/overlay/overlay_0102.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 102, 0
/* overlay 103 */ // .word 103, 0x021D0D80, filesize("base/overlay/overlay_0103.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 103, 0
/* overlay 104 */ // .word 104, 0x021D0D80, filesize("base/overlay/overlay_0104.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 104, 0
/* overlay 105 */ // .word 105, 0x021D0D80, filesize("base/overlay/overlay_0105.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 105, 0
/* overlay 106 */ // .word 106, 0x021D0D80, filesize("base/overlay/overlay_0106.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 106, 0
/* overlay 107 */ // .word 107, 0x021D0D80, filesize("base/overlay/overlay_0107.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 107, 0
/* overlay 108 */ // .word 108, 0x021D0D80, filesize("base/overlay/overlay_0108.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 108, 0
/* overlay 109 */ // .word 109, 0x021D0D80, filesize("base/overlay/overlay_0109.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 109, 0
/* overlay 110 */ // .word 110, 0x021D0D80, filesize("base/overlay/overlay_0110.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 110, 0
/* overlay 111 */ // .word 111, 0x021D0D80, filesize("base/overlay/overlay_0111.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 111, 0
/* overlay 112 */ // .word 112, 0x021D0D80, filesize("base/overlay/overlay_0112.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 112, 0
/* overlay 113 */ // .word 113, 0x021D0D80, filesize("base/overlay/overlay_0113.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 113, 0
/* overlay 114 */ // .word 114, 0x021D0D80, filesize("base/overlay/overlay_0114.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 114, 0
/* overlay 115 */ // .word 115, 0x021D0D80, filesize("base/overlay/overlay_0115.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 115, 0
/* overlay 116 */ // .word 116, 0x021D0D80, filesize("base/overlay/overlay_0116.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 116, 0
/* overlay 117 */ // .word 117, 0x021D0D80, filesize("base/overlay/overlay_0117.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 117, 0
/* overlay 118 */ // .word 118, 0x021D0D80, filesize("base/overlay/overlay_0118.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 118, 0
/* overlay 119 */ // .word 119, 0x021D0D80, filesize("base/overlay/overlay_0119.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 119, 0
/* overlay 120 */ // .word 120, 0x021D0D80, filesize("base/overlay/overlay_0120.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 120, 0
/* overlay 121 */ // .word 121, 0x021D0D80, filesize("base/overlay/overlay_0121.bin"), 0x00000000, 0x021D0D80, 0x021D0D84, 121, 0

.org 122 * 0x20 // jump to new overlays

.word 122, 0x023C8000, filesize("base/overlay/overlay_0122.bin"), 0x00000000, 0x023C8000, 0x023C8000, 122, 0    // arm9 expansion
.word 123, 0x023D0000, filesize("base/overlay/overlay_0123.bin"), 0x00000000, 0x023D0000, 0x023D0000, 123, 0    // battle overlay
.word 124, 0x023D0000, filesize("base/overlay/overlay_0124.bin"), 0x00000000, 0x023D0000, 0x023D0000, 124, 0    // field overlay
