/*
 * This file only contains byte constants for MIDI instructions
 */
                                  //command
                                      //channel
#define MIDI_NOTE_OFF           0b10000000
#define MIDI_NOTE_ON            0b10010000
#define MIDI_AFTERTOUCH         0b10100000
#define MIDI_CONT_CONTROLLER    0b10110000
#define MIDI_PATCH_CHANGE       0b11000000
#define MIDI_CH_PRESSURE        0b11010000
#define MIDI_PITCH_BEND         0b11100000
#define MIDI_NON_MUSICAL        0b11110000
#define MIDI_CHANGE_INSTRUMENT  0b11000000

/*
 * Every note identifier
 * Example: NOTE_DO_0
 *    DO note of first octave, 
 *    the last number represents the octavea 
 *    it starts counting at 0
 * Example: NOTE_RE_1_
 *    RE sharp note of second octave,
 *    last underscore means sharp
 */

#define NOTE_DO_0         0
#define NOTE_DO_0_        1
#define NOTE_RE_0         2
#define NOTE_RE_0_        3
#define NOTE_MI_0         4
#define NOTE_FA_0         5
#define NOTE_FA_0_        6
#define NOTE_SOL_0        7
#define NOTE_SOL_0_       8
#define NOTE_LA_0         9
#define NOTE_LA_0_        10
#define NOTE_SI_0         11

#define NOTE_DO_1         12
#define NOTE_DO_1_        13
#define NOTE_RE_1         14
#define NOTE_RE_1_        15
#define NOTE_MI_1         16
#define NOTE_FA_1         17
#define NOTE_FA_1_        18
#define NOTE_SOL_1        19
#define NOTE_SOL_1_       20
#define NOTE_LA_1         21
#define NOTE_LA_1_        22
#define NOTE_SI_1         23

#define NOTE_DO_2         24
#define NOTE_DO_2_        25
#define NOTE_RE_2         26
#define NOTE_RE_2_        27
#define NOTE_MI_2         28
#define NOTE_FA_2         29
#define NOTE_FA_2_        30
#define NOTE_SOL_2        31
#define NOTE_SOL_2_       32
#define NOTE_LA_2         33
#define NOTE_LA_2_        34
#define NOTE_SI_2         35

#define NOTE_DO_3         36
#define NOTE_DO_3_        37
#define NOTE_RE_3         38
#define NOTE_RE_3_        39
#define NOTE_MI_3         40
#define NOTE_FA_3         41
#define NOTE_FA_3_        42
#define NOTE_SOL_3        43
#define NOTE_SOL_3_       44
#define NOTE_LA_3         45
#define NOTE_LA_3_        46
#define NOTE_SI_3         47

#define NOTE_DO_4         48
#define NOTE_DO_4_        49
#define NOTE_RE_4         50
#define NOTE_RE_4_        51
#define NOTE_MI_4         52
#define NOTE_FA_4         53
#define NOTE_FA_4_        54
#define NOTE_SOL_4        55
#define NOTE_SOL_4_       56
#define NOTE_LA_4         57
#define NOTE_LA_4_        58
#define NOTE_SI_4         59

#define NOTE_DO_5         60
#define NOTE_DO_5_        61
#define NOTE_RE_5         62
#define NOTE_RE_5_        63
#define NOTE_MI_5         64
#define NOTE_FA_5         65
#define NOTE_FA_5_        66
#define NOTE_SOL_5        67
#define NOTE_SOL_5_       68
#define NOTE_LA_5         69
#define NOTE_LA_5_        70
#define NOTE_SI_5         71

#define NOTE_DO_6         72
#define NOTE_DO_6_        73
#define NOTE_RE_6         74
#define NOTE_RE_6_        75
#define NOTE_MI_6         76
#define NOTE_FA_6         77
#define NOTE_FA_6_        78
#define NOTE_SOL_6        79
#define NOTE_SOL_6_       80
#define NOTE_LA_6         81
#define NOTE_LA_6_        82
#define NOTE_SI_6         83

#define NOTE_DO_7         84
#define NOTE_DO_7_        85
#define NOTE_RE_7         86
#define NOTE_RE_7_        87
#define NOTE_MI_7         88
#define NOTE_FA_7         89
#define NOTE_FA_7_        90
#define NOTE_SOL_7        91
#define NOTE_SOL_7_       92
#define NOTE_LA_7         93
#define NOTE_LA_7_        94
#define NOTE_SI_7         95

#define NOTE_DO_8         96
#define NOTE_DO_8_        97
#define NOTE_RE_8         98
#define NOTE_RE_8_        99
#define NOTE_MI_8         100
#define NOTE_FA_8         101
#define NOTE_FA_8_        102
#define NOTE_SOL_8        103
#define NOTE_SOL_8_       104
#define NOTE_LA_8         105
#define NOTE_LA_8_        106
#define NOTE_SI_8         107

#define NOTE_DO_9         108
#define NOTE_DO_9_        109
#define NOTE_RE_9         110
#define NOTE_RE_9_        111
#define NOTE_MI_9         112
#define NOTE_FA_9         113
#define NOTE_FA_9_        114
#define NOTE_SOL_9        115
#define NOTE_SOL_9_       116
#define NOTE_LA_9         117
#define NOTE_LA_9_        118
#define NOTE_SI_9         119

#define NOTE_DO_10        120
#define NOTE_DO_10_       121
#define NOTE_RE_10        122
#define NOTE_RE_10_       123
#define NOTE_MI_10        124
#define NOTE_FA_10        125
#define NOTE_FA_10_       126
#define NOTE_SOL_10       127


/**
 * Instruments for MIDI
 */
#define INSTRUMENT_ACOUSTIC_GRAND_PIANO       0
#define INSTRUMENT_MARIMBA                    12
#define INSTRUMENT_XYLOPHONE                  13
#define INSTRUMENT_CHURCH_ORGAN               19
#define INSTRUMENT_ACCORDION                  21
#define INSTRUMENT_HARMONICA                  22
#define INSTRUMENT_ACOUSTIC_NYLON_GUITAR      25
#define INSTRUMENT_ACOUSTIC_BASS              32
#define INSTRUMENT_VIOLIN                     40
#define INSTRUMENT_CONTRABASS                 43
#define INSTRUMENT_ORCHESTRAL_HARP            46
#define INSTRUMENT_TRUMPET                    56
#define INSTRUMENT_TUBA                       58
#define INSTRUMENT_OBOE                       68
#define INSTRUMENT_CLARINET                   71
#define INSTRUMENT_FLUTE                      73
#define INSTRUMENT_PAN_FLUTE                  75
#define INSTRUMENT_BOTTLE_BLOW                76
#define INSTRUMENT_OCARINA                    79
#define INSTRUMENT_SCI-FI_EFFECT              103
#define INSTRUMENT_BANJO                      105
#define INSTRUMENT_STEEL_DRUMS                114
#define INSTRUMENT_TAIKO_DRUM                 116
#define INSTRUMENT_BREATH_NOISE               121
#define INSTRUMENT_BIRD_TWEET                 123
#define INSTRUMENT_APPLAUSE                   126
#define INSTRUMENT_GUN_SHOT                   127



 
