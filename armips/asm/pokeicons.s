.nds
.thumb

.open "base/arm9.bin", 0x02000000

.org 0x020F0780
.area 0x020F099C-.

// this will need to be moved eventually to accommodate adding new species
// but this is fine for now

/* SPECIES_NONE            */ .byte  0x0
/* SPECIES_BULBASAUR       */ .byte  0x1
/* SPECIES_IVYSAUR         */ .byte  0x1
/* SPECIES_VENUSAUR        */ .byte  0x1
/* SPECIES_CHARMANDER      */ .byte  0x0
/* SPECIES_CHARMELEON      */ .byte  0x0
/* SPECIES_CHARIZARD       */ .byte  0x0
/* SPECIES_SQUIRTLE        */ .byte  0x0
/* SPECIES_WARTORTLE       */ .byte  0x2
/* SPECIES_BLASTOISE       */ .byte  0x2
/* SPECIES_CATERPIE        */ .byte  0x1
/* SPECIES_METAPOD         */ .byte  0x1
/* SPECIES_BUTTERFREE      */ .byte  0x0
/* SPECIES_WEEDLE          */ .byte  0x2
/* SPECIES_KAKUNA          */ .byte  0x2
/* SPECIES_BEEDRILL        */ .byte  0x2
/* SPECIES_PIDGEY          */ .byte  0x0
/* SPECIES_PIDGEOTTO       */ .byte  0x0
/* SPECIES_PIDGEOT         */ .byte  0x0
/* SPECIES_RATTATA         */ .byte  0x2
/* SPECIES_RATICATE        */ .byte  0x2
/* SPECIES_SPEAROW         */ .byte  0x0
/* SPECIES_FEAROW          */ .byte  0x0
/* SPECIES_EKANS           */ .byte  0x2
/* SPECIES_ARBOK           */ .byte  0x2
/* SPECIES_PIKACHU         */ .byte  0x2
/* SPECIES_RAICHU          */ .byte  0x0
/* SPECIES_SANDSHREW       */ .byte  0x2
/* SPECIES_SANDSLASH       */ .byte  0x2
/* SPECIES_NIDORAN_F       */ .byte  0x0
/* SPECIES_NIDORINA        */ .byte  0x0
/* SPECIES_NIDOQUEEN       */ .byte  0x2
/* SPECIES_NIDORAN_M       */ .byte  0x2
/* SPECIES_NIDORINO        */ .byte  0x2
/* SPECIES_NIDOKING        */ .byte  0x2
/* SPECIES_CLEFAIRY        */ .byte  0x0
/* SPECIES_CLEFABLE        */ .byte  0x0
/* SPECIES_VULPIX          */ .byte  0x0
/* SPECIES_NINETALES       */ .byte  0x1
/* SPECIES_JIGGLYPUFF      */ .byte  0x0
/* SPECIES_WIGGLYTUFF      */ .byte  0x0
/* SPECIES_ZUBAT           */ .byte  0x2
/* SPECIES_GOLBAT          */ .byte  0x2
/* SPECIES_ODDISH          */ .byte  0x1
/* SPECIES_GLOOM           */ .byte  0x0
/* SPECIES_VILEPLUME       */ .byte  0x0
/* SPECIES_PARAS           */ .byte  0x0
/* SPECIES_PARASECT        */ .byte  0x0
/* SPECIES_VENONAT         */ .byte  0x2
/* SPECIES_VENOMOTH        */ .byte  0x2
/* SPECIES_DIGLETT         */ .byte  0x2
/* SPECIES_DUGTRIO         */ .byte  0x2
/* SPECIES_MEOWTH          */ .byte  0x1
/* SPECIES_PERSIAN         */ .byte  0x1
/* SPECIES_PSYDUCK         */ .byte  0x1
/* SPECIES_GOLDUCK         */ .byte  0x0
/* SPECIES_MANKEY          */ .byte  0x1
/* SPECIES_PRIMEAPE        */ .byte  0x2
/* SPECIES_GROWLITHE       */ .byte  0x0
/* SPECIES_ARCANINE        */ .byte  0x0
/* SPECIES_POLIWAG         */ .byte  0x0
/* SPECIES_POLIWHIRL       */ .byte  0x0
/* SPECIES_POLIWRATH       */ .byte  0x0
/* SPECIES_ABRA            */ .byte  0x2
/* SPECIES_KADABRA         */ .byte  0x2
/* SPECIES_ALAKAZAM        */ .byte  0x2
/* SPECIES_MACHOP          */ .byte  0x0
/* SPECIES_MACHOKE         */ .byte  0x2
/* SPECIES_MACHAMP         */ .byte  0x0
/* SPECIES_BELLSPROUT      */ .byte  0x1
/* SPECIES_WEEPINBELL      */ .byte  0x1
/* SPECIES_VICTREEBEL      */ .byte  0x1
/* SPECIES_TENTACOOL       */ .byte  0x0
/* SPECIES_TENTACRUEL      */ .byte  0x0
/* SPECIES_GEODUDE         */ .byte  0x1
/* SPECIES_GRAVELER        */ .byte  0x1
/* SPECIES_GOLEM           */ .byte  0x2
/* SPECIES_PONYTA          */ .byte  0x0
/* SPECIES_RAPIDASH        */ .byte  0x0
/* SPECIES_SLOWPOKE        */ .byte  0x0
/* SPECIES_SLOWBRO         */ .byte  0x0
/* SPECIES_MAGNEMITE       */ .byte  0x0
/* SPECIES_MAGNETON        */ .byte  0x0
/* SPECIES_FARFETCHD       */ .byte  0x1
/* SPECIES_DODUO           */ .byte  0x2
/* SPECIES_DODRIO          */ .byte  0x2
/* SPECIES_SEEL            */ .byte  0x0
/* SPECIES_DEWGONG         */ .byte  0x2
/* SPECIES_GRIMER          */ .byte  0x2
/* SPECIES_MUK             */ .byte  0x2
/* SPECIES_SHELLDER        */ .byte  0x2
/* SPECIES_CLOYSTER        */ .byte  0x2
/* SPECIES_GASTLY          */ .byte  0x2
/* SPECIES_HAUNTER         */ .byte  0x2
/* SPECIES_GENGAR          */ .byte  0x2
/* SPECIES_ONIX            */ .byte  0x2
/* SPECIES_DROWZEE         */ .byte  0x2
/* SPECIES_HYPNO           */ .byte  0x2
/* SPECIES_KRABBY          */ .byte  0x0
/* SPECIES_KINGLER         */ .byte  0x0
/* SPECIES_VOLTORB         */ .byte  0x0
/* SPECIES_ELECTRODE       */ .byte  0x0
/* SPECIES_EXEGGCUTE       */ .byte  0x0
/* SPECIES_EXEGGUTOR       */ .byte  0x1
/* SPECIES_CUBONE          */ .byte  0x2
/* SPECIES_MAROWAK         */ .byte  0x2
/* SPECIES_HITMONLEE       */ .byte  0x2
/* SPECIES_HITMONCHAN      */ .byte  0x2
/* SPECIES_LICKITUNG       */ .byte  0x0
/* SPECIES_KOFFING         */ .byte  0x2
/* SPECIES_WEEZING         */ .byte  0x2
/* SPECIES_RHYHORN         */ .byte  0x1
/* SPECIES_RHYDON          */ .byte  0x1
/* SPECIES_CHANSEY         */ .byte  0x0
/* SPECIES_TANGELA         */ .byte  0x0
/* SPECIES_KANGASKHAN      */ .byte  0x2
/* SPECIES_HORSEA          */ .byte  0x0
/* SPECIES_SEADRA          */ .byte  0x0
/* SPECIES_GOLDEEN         */ .byte  0x0
/* SPECIES_SEAKING         */ .byte  0x0
/* SPECIES_STARYU          */ .byte  0x2
/* SPECIES_STARMIE         */ .byte  0x2
/* SPECIES_MR_MIME         */ .byte  0x0
/* SPECIES_SCYTHER         */ .byte  0x1
/* SPECIES_JYNX            */ .byte  0x2
/* SPECIES_ELECTABUZZ      */ .byte  0x1
/* SPECIES_MAGMAR          */ .byte  0x0
/* SPECIES_PINSIR          */ .byte  0x2
/* SPECIES_TAUROS          */ .byte  0x2
/* SPECIES_MAGIKARP        */ .byte  0x0
/* SPECIES_GYARADOS        */ .byte  0x0
/* SPECIES_LAPRAS          */ .byte  0x2
/* SPECIES_DITTO           */ .byte  0x2
/* SPECIES_EEVEE           */ .byte  0x2
/* SPECIES_VAPOREON        */ .byte  0x0
/* SPECIES_JOLTEON         */ .byte  0x2
/* SPECIES_FLAREON         */ .byte  0x0
/* SPECIES_PORYGON         */ .byte  0x0
/* SPECIES_OMANYTE         */ .byte  0x0
/* SPECIES_OMASTAR         */ .byte  0x0
/* SPECIES_KABUTO          */ .byte  0x2
/* SPECIES_KABUTOPS        */ .byte  0x2
/* SPECIES_AERODACTYL      */ .byte  0x2
/* SPECIES_SNORLAX         */ .byte  0x1
/* SPECIES_ARTICUNO        */ .byte  0x2
/* SPECIES_ZAPDOS          */ .byte  0x0
/* SPECIES_MOLTRES         */ .byte  0x0
/* SPECIES_DRATINI         */ .byte  0x0
/* SPECIES_DRAGONAIR       */ .byte  0x0
/* SPECIES_DRAGONITE       */ .byte  0x2
/* SPECIES_MEWTWO          */ .byte  0x2
/* SPECIES_MEW             */ .byte  0x0
/* SPECIES_CHIKORITA       */ .byte  0x1
/* SPECIES_BAYLEEF         */ .byte  0x1
/* SPECIES_MEGANIUM        */ .byte  0x1
/* SPECIES_CYNDAQUIL       */ .byte  0x1
/* SPECIES_QUILAVA         */ .byte  0x1
/* SPECIES_TYPHLOSION      */ .byte  0x1
/* SPECIES_TOTODILE        */ .byte  0x0
/* SPECIES_CROCONAW        */ .byte  0x0
/* SPECIES_FERALIGATR      */ .byte  0x0
/* SPECIES_SENTRET         */ .byte  0x2
/* SPECIES_FURRET          */ .byte  0x2
/* SPECIES_HOOTHOOT        */ .byte  0x2
/* SPECIES_NOCTOWL         */ .byte  0x2
/* SPECIES_LEDYBA          */ .byte  0x0
/* SPECIES_LEDIAN          */ .byte  0x0
/* SPECIES_SPINARAK        */ .byte  0x1
/* SPECIES_ARIADOS         */ .byte  0x0
/* SPECIES_CROBAT          */ .byte  0x2
/* SPECIES_CHINCHOU        */ .byte  0x2
/* SPECIES_LANTURN         */ .byte  0x0
/* SPECIES_PICHU           */ .byte  0x1
/* SPECIES_CLEFFA          */ .byte  0x0
/* SPECIES_IGGLYBUFF       */ .byte  0x1
/* SPECIES_TOGEPI          */ .byte  0x0
/* SPECIES_TOGETIC         */ .byte  0x0
/* SPECIES_NATU            */ .byte  0x1
/* SPECIES_XATU            */ .byte  0x1
/* SPECIES_MAREEP          */ .byte  0x0
/* SPECIES_FLAAFFY         */ .byte  0x0
/* SPECIES_AMPHAROS        */ .byte  0x0
/* SPECIES_BELLOSSOM       */ .byte  0x1
/* SPECIES_MARILL          */ .byte  0x0
/* SPECIES_AZUMARILL       */ .byte  0x0
/* SPECIES_SUDOWOODO       */ .byte  0x1
/* SPECIES_POLITOED        */ .byte  0x1
/* SPECIES_HOPPIP          */ .byte  0x1
/* SPECIES_SKIPLOOM        */ .byte  0x1
/* SPECIES_JUMPLUFF        */ .byte  0x2
/* SPECIES_AIPOM           */ .byte  0x2
/* SPECIES_SUNKERN         */ .byte  0x1
/* SPECIES_SUNFLORA        */ .byte  0x1
/* SPECIES_YANMA           */ .byte  0x1
/* SPECIES_WOOPER          */ .byte  0x0
/* SPECIES_QUAGSIRE        */ .byte  0x0
/* SPECIES_ESPEON          */ .byte  0x2
/* SPECIES_UMBREON         */ .byte  0x0
/* SPECIES_MURKROW         */ .byte  0x2
/* SPECIES_SLOWKING        */ .byte  0x0
/* SPECIES_MISDREAVUS      */ .byte  0x0
/* SPECIES_UNOWN           */ .byte  0x0
/* SPECIES_WOBBUFFET       */ .byte  0x0
/* SPECIES_GIRAFARIG       */ .byte  0x1
/* SPECIES_PINECO          */ .byte  0x0
/* SPECIES_FORRETRESS      */ .byte  0x2
/* SPECIES_DUNSPARCE       */ .byte  0x0
/* SPECIES_GLIGAR          */ .byte  0x0
/* SPECIES_STEELIX         */ .byte  0x0
/* SPECIES_SNUBBULL        */ .byte  0x0
/* SPECIES_GRANBULL        */ .byte  0x2
/* SPECIES_QWILFISH        */ .byte  0x0
/* SPECIES_SCIZOR          */ .byte  0x0
/* SPECIES_SHUCKLE         */ .byte  0x1
/* SPECIES_HERACROSS       */ .byte  0x0
/* SPECIES_SNEASEL         */ .byte  0x0
/* SPECIES_TEDDIURSA       */ .byte  0x0
/* SPECIES_URSARING        */ .byte  0x2
/* SPECIES_SLUGMA          */ .byte  0x0
/* SPECIES_MAGCARGO        */ .byte  0x0
/* SPECIES_SWINUB          */ .byte  0x2
/* SPECIES_PILOSWINE       */ .byte  0x2
/* SPECIES_CORSOLA         */ .byte  0x0
/* SPECIES_REMORAID        */ .byte  0x0
/* SPECIES_OCTILLERY       */ .byte  0x0
/* SPECIES_DELIBIRD        */ .byte  0x1
/* SPECIES_MANTINE         */ .byte  0x2
/* SPECIES_SKARMORY        */ .byte  0x0
/* SPECIES_HOUNDOUR        */ .byte  0x0
/* SPECIES_HOUNDOOM        */ .byte  0x0
/* SPECIES_KINGDRA         */ .byte  0x0
/* SPECIES_PHANPY          */ .byte  0x0
/* SPECIES_DONPHAN         */ .byte  0x0
/* SPECIES_PORYGON2        */ .byte  0x0
/* SPECIES_STANTLER        */ .byte  0x2
/* SPECIES_SMEARGLE        */ .byte  0x1
/* SPECIES_TYROGUE         */ .byte  0x2
/* SPECIES_HITMONTOP       */ .byte  0x2
/* SPECIES_SMOOCHUM        */ .byte  0x1
/* SPECIES_ELEKID          */ .byte  0x1
/* SPECIES_MAGBY           */ .byte  0x0
/* SPECIES_MILTANK         */ .byte  0x0
/* SPECIES_BLISSEY         */ .byte  0x0
/* SPECIES_RAIKOU          */ .byte  0x2
/* SPECIES_ENTEI           */ .byte  0x2
/* SPECIES_SUICUNE         */ .byte  0x2
/* SPECIES_LARVITAR        */ .byte  0x1
/* SPECIES_PUPITAR         */ .byte  0x2
/* SPECIES_TYRANITAR       */ .byte  0x1
/* SPECIES_LUGIA           */ .byte  0x0
/* SPECIES_HO_OH           */ .byte  0x1
/* SPECIES_CELEBI          */ .byte  0x1
/* SPECIES_TREECKO         */ .byte  0x1
/* SPECIES_GROVYLE         */ .byte  0x1
/* SPECIES_SCEPTILE        */ .byte  0x1
/* SPECIES_TORCHIC         */ .byte  0x0
/* SPECIES_COMBUSKEN       */ .byte  0x0
/* SPECIES_BLAZIKEN        */ .byte  0x0
/* SPECIES_MUDKIP          */ .byte  0x0
/* SPECIES_MARSHTOMP       */ .byte  0x0
/* SPECIES_SWAMPERT        */ .byte  0x0
/* SPECIES_POOCHYENA       */ .byte  0x1
/* SPECIES_MIGHTYENA       */ .byte  0x1
/* SPECIES_ZIGZAGOON       */ .byte  0x2
/* SPECIES_LINOONE         */ .byte  0x2
/* SPECIES_WURMPLE         */ .byte  0x0
/* SPECIES_SILCOON         */ .byte  0x2
/* SPECIES_BEAUTIFLY       */ .byte  0x0
/* SPECIES_CASCOON         */ .byte  0x2
/* SPECIES_DUSTOX          */ .byte  0x1
/* SPECIES_LOTAD           */ .byte  0x1
/* SPECIES_LOMBRE          */ .byte  0x1
/* SPECIES_LUDICOLO        */ .byte  0x1
/* SPECIES_SEEDOT          */ .byte  0x2
/* SPECIES_NUZLEAF         */ .byte  0x1
/* SPECIES_SHIFTRY         */ .byte  0x0
/* SPECIES_TAILLOW         */ .byte  0x2
/* SPECIES_SWELLOW         */ .byte  0x2
/* SPECIES_WINGULL         */ .byte  0x0
/* SPECIES_PELIPPER        */ .byte  0x2
/* SPECIES_RALTS           */ .byte  0x1
/* SPECIES_KIRLIA          */ .byte  0x1
/* SPECIES_GARDEVOIR       */ .byte  0x1
/* SPECIES_SURSKIT         */ .byte  0x0
/* SPECIES_MASQUERAIN      */ .byte  0x0
/* SPECIES_SHROOMISH       */ .byte  0x1
/* SPECIES_BRELOOM         */ .byte  0x1
/* SPECIES_SLAKOTH         */ .byte  0x2
/* SPECIES_VIGOROTH        */ .byte  0x2
/* SPECIES_SLAKING         */ .byte  0x2
/* SPECIES_NINCADA         */ .byte  0x1
/* SPECIES_NINJASK         */ .byte  0x1
/* SPECIES_SHEDINJA        */ .byte  0x1
/* SPECIES_WHISMUR         */ .byte  0x1
/* SPECIES_LOUDRED         */ .byte  0x2
/* SPECIES_EXPLOUD         */ .byte  0x2
/* SPECIES_MAKUHITA        */ .byte  0x1
/* SPECIES_HARIYAMA        */ .byte  0x2
/* SPECIES_AZURILL         */ .byte  0x0
/* SPECIES_NOSEPASS        */ .byte  0x0
/* SPECIES_SKITTY          */ .byte  0x0
/* SPECIES_DELCATTY        */ .byte  0x2
/* SPECIES_SABLEYE         */ .byte  0x2
/* SPECIES_MAWILE          */ .byte  0x2
/* SPECIES_ARON            */ .byte  0x2
/* SPECIES_LAIRON          */ .byte  0x2
/* SPECIES_AGGRON          */ .byte  0x2
/* SPECIES_MEDITITE        */ .byte  0x0
/* SPECIES_MEDICHAM        */ .byte  0x0
/* SPECIES_ELECTRIKE       */ .byte  0x1
/* SPECIES_MANECTRIC       */ .byte  0x0
/* SPECIES_PLUSLE          */ .byte  0x0
/* SPECIES_MINUN           */ .byte  0x0
/* SPECIES_VOLBEAT         */ .byte  0x0
/* SPECIES_ILLUMISE        */ .byte  0x2
/* SPECIES_ROSELIA         */ .byte  0x0
/* SPECIES_GULPIN          */ .byte  0x1
/* SPECIES_SWALOT          */ .byte  0x2
/* SPECIES_CARVANHA        */ .byte  0x0
/* SPECIES_SHARPEDO        */ .byte  0x0
/* SPECIES_WAILMER         */ .byte  0x2
/* SPECIES_WAILORD         */ .byte  0x0
/* SPECIES_NUMEL           */ .byte  0x1
/* SPECIES_CAMERUPT        */ .byte  0x0
/* SPECIES_TORKOAL         */ .byte  0x0
/* SPECIES_SPOINK          */ .byte  0x0
/* SPECIES_GRUMPIG         */ .byte  0x2
/* SPECIES_SPINDA          */ .byte  0x1
/* SPECIES_TRAPINCH        */ .byte  0x0
/* SPECIES_VIBRAVA         */ .byte  0x1
/* SPECIES_FLYGON          */ .byte  0x1
/* SPECIES_CACNEA          */ .byte  0x1
/* SPECIES_CACTURNE        */ .byte  0x1
/* SPECIES_SWABLU          */ .byte  0x0
/* SPECIES_ALTARIA         */ .byte  0x0
/* SPECIES_ZANGOOSE        */ .byte  0x0
/* SPECIES_SEVIPER         */ .byte  0x2
/* SPECIES_LUNATONE        */ .byte  0x1
/* SPECIES_SOLROCK         */ .byte  0x0
/* SPECIES_BARBOACH        */ .byte  0x0
/* SPECIES_WHISCASH        */ .byte  0x0
/* SPECIES_CORPHISH        */ .byte  0x0
/* SPECIES_CRAWDAUNT       */ .byte  0x0
/* SPECIES_BALTOY          */ .byte  0x2
/* SPECIES_CLAYDOL         */ .byte  0x0
/* SPECIES_LILEEP          */ .byte  0x2
/* SPECIES_CRADILY         */ .byte  0x1
/* SPECIES_ANORITH         */ .byte  0x0
/* SPECIES_ARMALDO         */ .byte  0x2
/* SPECIES_FEEBAS          */ .byte  0x2
/* SPECIES_MILOTIC         */ .byte  0x2
/* SPECIES_CASTFORM        */ .byte  0x0
/* SPECIES_KECLEON         */ .byte  0x1
/* SPECIES_SHUPPET         */ .byte  0x0
/* SPECIES_BANETTE         */ .byte  0x0
/* SPECIES_DUSKULL         */ .byte  0x0
/* SPECIES_DUSCLOPS        */ .byte  0x0
/* SPECIES_TROPIUS         */ .byte  0x1
/* SPECIES_CHIMECHO        */ .byte  0x0
/* SPECIES_ABSOL           */ .byte  0x0
/* SPECIES_WYNAUT          */ .byte  0x0
/* SPECIES_SNORUNT         */ .byte  0x2
/* SPECIES_GLALIE          */ .byte  0x0
/* SPECIES_SPHEAL          */ .byte  0x2
/* SPECIES_SEALEO          */ .byte  0x2
/* SPECIES_WALREIN         */ .byte  0x0
/* SPECIES_CLAMPERL        */ .byte  0x0
/* SPECIES_HUNTAIL         */ .byte  0x0
/* SPECIES_GOREBYSS        */ .byte  0x0
/* SPECIES_RELICANTH       */ .byte  0x2
/* SPECIES_LUVDISC         */ .byte  0x0
/* SPECIES_BAGON           */ .byte  0x0
/* SPECIES_SHELGON         */ .byte  0x2
/* SPECIES_SALAMENCE       */ .byte  0x0
/* SPECIES_BELDUM          */ .byte  0x0
/* SPECIES_METANG          */ .byte  0x0
/* SPECIES_METAGROSS       */ .byte  0x0
/* SPECIES_REGIROCK        */ .byte  0x2
/* SPECIES_REGICE          */ .byte  0x0
/* SPECIES_REGISTEEL       */ .byte  0x2
/* SPECIES_LATIAS          */ .byte  0x0
/* SPECIES_LATIOS          */ .byte  0x0
/* SPECIES_KYOGRE          */ .byte  0x2
/* SPECIES_GROUDON         */ .byte  0x0
/* SPECIES_RAYQUAZA        */ .byte  0x1
/* SPECIES_JIRACHI         */ .byte  0x0
/* SPECIES_DEOXYS          */ .byte  0x0
/* SPECIES_TURTWIG         */ .byte  0x1
/* SPECIES_GROTLE          */ .byte  0x1
/* SPECIES_TORTERRA        */ .byte  0x1
/* SPECIES_CHIMCHAR        */ .byte  0x1
/* SPECIES_MONFERNO        */ .byte  0x0
/* SPECIES_INFERNAPE       */ .byte  0x0
/* SPECIES_PIPLUP          */ .byte  0x0
/* SPECIES_PRINPLUP        */ .byte  0x0
/* SPECIES_EMPOLEON        */ .byte  0x0
/* SPECIES_STARLY          */ .byte  0x0
/* SPECIES_STARAVIA        */ .byte  0x0
/* SPECIES_STARAPTOR       */ .byte  0x0
/* SPECIES_BIDOOF          */ .byte  0x2
/* SPECIES_BIBAREL         */ .byte  0x2
/* SPECIES_KRICKETOT       */ .byte  0x2
/* SPECIES_KRICKETUNE      */ .byte  0x2
/* SPECIES_SHINX           */ .byte  0x0
/* SPECIES_LUXIO           */ .byte  0x0
/* SPECIES_LUXRAY          */ .byte  0x0
/* SPECIES_BUDEW           */ .byte  0x1
/* SPECIES_ROSERADE        */ .byte  0x0
/* SPECIES_CRANIDOS        */ .byte  0x0
/* SPECIES_RAMPARDOS       */ .byte  0x0
/* SPECIES_SHIELDON        */ .byte  0x1
/* SPECIES_BASTIODON       */ .byte  0x1
/* SPECIES_BURMY           */ .byte  0x1
/* SPECIES_WORMADAM        */ .byte  0x1
/* SPECIES_MOTHIM          */ .byte  0x0
/* SPECIES_COMBEE          */ .byte  0x0
/* SPECIES_VESPIQUEN       */ .byte  0x0
/* SPECIES_PACHIRISU       */ .byte  0x0
/* SPECIES_BUIZEL          */ .byte  0x0
/* SPECIES_FLOATZEL        */ .byte  0x0
/* SPECIES_CHERUBI         */ .byte  0x1
/* SPECIES_CHERRIM         */ .byte  0x0
/* SPECIES_SHELLOS         */ .byte  0x0
/* SPECIES_GASTRODON       */ .byte  0x0
/* SPECIES_AMBIPOM         */ .byte  0x2
/* SPECIES_DRIFLOON        */ .byte  0x2
/* SPECIES_DRIFBLIM        */ .byte  0x2
/* SPECIES_BUNEARY         */ .byte  0x2
/* SPECIES_LOPUNNY         */ .byte  0x2
/* SPECIES_MISMAGIUS       */ .byte  0x2
/* SPECIES_HONCHKROW       */ .byte  0x2
/* SPECIES_GLAMEOW         */ .byte  0x0
/* SPECIES_PURUGLY         */ .byte  0x0
/* SPECIES_CHINGLING       */ .byte  0x1
/* SPECIES_STUNKY          */ .byte  0x2
/* SPECIES_SKUNTANK        */ .byte  0x2
/* SPECIES_BRONZOR         */ .byte  0x0
/* SPECIES_BRONZONG        */ .byte  0x0
/* SPECIES_BONSLY          */ .byte  0x1
/* SPECIES_MIMEJR          */ .byte  0x0
/* SPECIES_HAPPINY         */ .byte  0x0
/* SPECIES_CHATOT          */ .byte  0x0
/* SPECIES_SPIRITOMB       */ .byte  0x2
/* SPECIES_GIBLE           */ .byte  0x0
/* SPECIES_GABITE          */ .byte  0x0
/* SPECIES_GARCHOMP        */ .byte  0x0
/* SPECIES_MUNCHLAX        */ .byte  0x0
/* SPECIES_RIOLU           */ .byte  0x2
/* SPECIES_LUCARIO         */ .byte  0x2
/* SPECIES_HIPPOPOTAS      */ .byte  0x1
/* SPECIES_HIPPOWDON       */ .byte  0x1
/* SPECIES_SKORUPI         */ .byte  0x0
/* SPECIES_DRAPION         */ .byte  0x2
/* SPECIES_CROAGUNK        */ .byte  0x0
/* SPECIES_TOXICROAK       */ .byte  0x0
/* SPECIES_CARNIVINE       */ .byte  0x1
/* SPECIES_FINNEON         */ .byte  0x0
/* SPECIES_LUMINEON        */ .byte  0x0
/* SPECIES_MANTYKE         */ .byte  0x0
/* SPECIES_SNOVER          */ .byte  0x1
/* SPECIES_ABOMASNOW       */ .byte  0x1
/* SPECIES_WEAVILE         */ .byte  0x0
/* SPECIES_MAGNEZONE       */ .byte  0x0
/* SPECIES_LICKILICKY      */ .byte  0x1
/* SPECIES_RHYPERIOR       */ .byte  0x0
/* SPECIES_TANGROWTH       */ .byte  0x0
/* SPECIES_ELECTIVIRE      */ .byte  0x1
/* SPECIES_MAGMORTAR       */ .byte  0x0
/* SPECIES_TOGEKISS        */ .byte  0x2
/* SPECIES_YANMEGA         */ .byte  0x1
/* SPECIES_LEAFEON         */ .byte  0x1
/* SPECIES_GLACEON         */ .byte  0x0
/* SPECIES_GLISCOR         */ .byte  0x2
/* SPECIES_MAMOSWINE       */ .byte  0x2
/* SPECIES_PORYGON_Z       */ .byte  0x0
/* SPECIES_GALLADE         */ .byte  0x1
/* SPECIES_PROBOPASS       */ .byte  0x0
/* SPECIES_DUSKNOIR        */ .byte  0x2
/* SPECIES_FROSLASS        */ .byte  0x0
/* SPECIES_ROTOM           */ .byte  0x0
/* SPECIES_UXIE            */ .byte  0x0
/* SPECIES_MESPRIT         */ .byte  0x0
/* SPECIES_AZELF           */ .byte  0x0
/* SPECIES_DIALGA          */ .byte  0x2
/* SPECIES_PALKIA          */ .byte  0x2
/* SPECIES_HEATRAN         */ .byte  0x0
/* SPECIES_REGIGIGAS       */ .byte  0x0
/* SPECIES_GIRATINA        */ .byte  0x0
/* SPECIES_CRESSELIA       */ .byte  0x0
/* SPECIES_PHIONE          */ .byte  0x0
/* SPECIES_MANAPHY         */ .byte  0x0
/* SPECIES_DARKRAI         */ .byte  0x0
/* SPECIES_SHAYMIN         */ .byte  0x1
/* SPECIES_ARCEUS          */ .byte  0x1
/* SPECIES_EGG             */ .byte  0x1
/* manaphy egg             */ .byte  0x1
/* SPECIES_DEOXYS_ATTACK   */ .byte  0x0
/* SPECIES_DEOXYS_DEFENSE  */ .byte  0x0
/* SPECIES_DEOXYS_SPEED    */ .byte  0x0
/* unown a                 */ .byte  0x0
/* unown b                 */ .byte  0x0
/* unown c                 */ .byte  0x0
/* unown d                 */ .byte  0x0
/* unown e                 */ .byte  0x0
/* unown f                 */ .byte  0x0
/* unown g                 */ .byte  0x0
/* unown h                 */ .byte  0x0
/* unown i                 */ .byte  0x0
/* unown j                 */ .byte  0x0
/* unown k                 */ .byte  0x0
/* unown l                 */ .byte  0x0
/* unown m                 */ .byte  0x0
/* unown n                 */ .byte  0x0
/* unown o                 */ .byte  0x0
/* unown p                 */ .byte  0x0
/* unown q                 */ .byte  0x0
/* unown r                 */ .byte  0x0
/* unown s                 */ .byte  0x0
/* unown t                 */ .byte  0x0
/* unown u                 */ .byte  0x0
/* unown v                 */ .byte  0x0
/* unown w                 */ .byte  0x0
/* unown x                 */ .byte  0x0
/* unown y                 */ .byte  0x0
/* unown z                 */ .byte  0x0
/* unown !                 */ .byte  0x0
/* unown ?                 */ .byte  0x0
/* burmy sandy             */ .byte  0x1
/* burmy trash             */ .byte  0x0
/* wormadam sandy          */ .byte  0x1
/* wormadam trash          */ .byte  0x0
/* east shellos            */ .byte  0x0
/* east gastrodon          */ .byte  0x0
/* giratina origin         */ .byte  0x0
/* sky shaymin             */ .byte  0x1
/* rotom heat              */ .byte  0x0
/* rotom fridge            */ .byte  0x0
/* rotom wash              */ .byte  0x0
/* rotom fan               */ .byte  0x0
/* rotom lawnmower         */ .byte  0x0

.endarea
.close