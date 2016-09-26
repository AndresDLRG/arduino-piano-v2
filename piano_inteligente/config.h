#include <LiquidCrystal.h>

/************************************************************************************
 +++++++++++++++ EVERYTHING ON THIS FILE WILL BE SHARED AMONG OTHERS ++++++++++++++++
 ************************************************************************************/


/************************************************************************************
 *                              DEFINE ALL PINS                                     *
 ************************************************************************************/
 
// Pins used for the piano keys
#define PIN_DO            47
#define PIN_DO_           46
#define PIN_RE            45
#define PIN_RE_           44
#define PIN_MI            43
#define PIN_FA            42
#define PIN_FA_           41
#define PIN_SOL           40
#define PIN_SOL_          39
#define PIN_LA            38
#define PIN_LA_           37
#define PIN_SI            36

// Pins for the LCD screen
#define PIN_RS            33
#define PIN_ENABLE        32
#define PIN_DB4           31
#define PIN_DB5           30
#define PIN_DB6           29
#define PIN_DB7           28

// Pins for the keypad
#define PIN_KEYPAD_ROW_0  13
#define PIN_KEYPAD_ROW_1  12
#define PIN_KEYPAD_ROW_2  11
#define PIN_KEYPAD_ROW_3  10
#define PIN_KEYPAD_COL_0  9
#define PIN_KEYPAD_COL_1  8
#define PIN_KEYPAD_COL_2  7

// Pins for SD card reader
// Should not be change or errors migth happen
#define PIN_MISO          50
#define PIN_MOSI          51
#define PIN_SCK           52
#define PIN_CS            53


/************************************************************************************
 *                              DEFINE ALL STRUCTS                                  *
 ************************************************************************************/

// The struct for managing Melodies
struct Melody {
  char name[25];
  int notes[50];
  int times[50];
  int rests[50];
  int size;
};


/************************************************************************************
 *                              CONFIGURE THE KEYPAD                                *
 ************************************************************************************/

// 4 rows, 3 cols 
const char KEYPAD_KEYS[4][3] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
//connect to the row pinouts of the keypad
byte keypadRowsPins[4] = {PIN_KEYPAD_ROW_0, PIN_KEYPAD_ROW_1, PIN_KEYPAD_ROW_2, PIN_KEYPAD_ROW_3}; 
//connect to the column pinouts
byte keypadColsPins[3] = {PIN_KEYPAD_COL_0, PIN_KEYPAD_COL_1, PIN_KEYPAD_COL_2}; 
Keypad keypad = Keypad( makeKeymap(KEYPAD_KEYS), keypadRowsPins, keypadColsPins, 4, 3);


/************************************************************************************
 *                           CONFIGURE THE LCD SCREEN                               *
 ************************************************************************************/

// (RS, Enable, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(PIN_RS, PIN_ENABLE, PIN_DB4, PIN_DB5, PIN_DB6, PIN_DB7);

// Custom characters
byte rigthArrow[8] = {
  0b00000,
  0b01000,
  0b01100,
  0b11110,
  0b11111,
  0b11110,
  0b01100,
  0b01000
};
byte leftArrow[8] = {
  0b00000,
  0b00010,
  0b00110,
  0b01110,
  0b11111,
  0b01110,
  0b00110,
  0b00010
};
byte downArrow[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b01110,
  0b00100
};
byte upArrow[8] = {
  0b00100,
  0b01110,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

/************************************************************************************
 *                                MENU CONFIGURATION                                *
 ************************************************************************************/
// Main menu
char *MENU_MAIN[] = {
  "MODO LIBRE",
  "MMODO ESCUCHA",
  "MODO APRENDE",
  "INSTRUMENTOS"
};
byte MENU_MAIN_SIZE = 4;

 
/************************************************************************************
 *                              MIDI CONFIGURATION                                  *
 ************************************************************************************/

#define MIDI_BAUDS  19200
#define MIDI_VOLUME 100


/************************************************************************************
 *                                    CONSTANTS                                     *
 ************************************************************************************/
 
/*
 * This array reduce the code a lot because with it a loop can check
 * whats note is going to be played by each pin key
 */
// do, do#, re, re#, mi, fa, fa#, sol, sol#, la, la#, si
const uint8_t PINS_INPUT[] = {  PIN_DO,   PIN_DO_,  PIN_RE,   PIN_RE_,
                                PIN_MI,   PIN_FA,   PIN_FA_,  PIN_SOL,
                                PIN_SOL_, PIN_LA,   PIN_LA_,  PIN_SI};
// Note that each pin represent
const uint8_t PIN_NOTES[] = { NOTE_DO_0,    NOTE_DO_0_, NOTE_RE_0,  NOTE_RE_0_,
                              NOTE_MI_0,    NOTE_FA_0,  NOTE_FA_0_, NOTE_SOL_0,
                              NOTE_SOL_0_,  NOTE_LA_0,  NOTE_LA_0_, NOTE_SI_0};
// Keep the size apart
const uint8_t PINS_PIANO_KEY_SIZE = 12;

// Screen constants
#define SCREEN_MAIN_MENU                0
#define SCREEN_FREE_MODE                1
#define SCREEN_LISTEN_MODE_SELECTION    2
#define SCREEN_LISTEN_MODE_PLAYING      3
#define SCREEN_LEARN_MODE_SELECTION     4
#define SCREEN_LEARN_MODE_PLAYING       5
#define SCREEN_INSTRUMENT_SELECTION     6

// LCD configuration
#define LCD_ROWS    2             
#define LCD_COLS    16

