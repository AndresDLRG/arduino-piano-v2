
/********************************************
 *            PUBLIC LIBRARIES              *
 ********************************************/
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <SPI.h>
#include <SD.h>


/********************************************
 *      SOME METHODS DECLARACTIONS          *
 ********************************************/
void showMainMenuScreen();
void showFreeModeScreen();
void showListenModeSelectionScreen();
void showListenModePlayingScreen(String);
void showLearnModeSelectionScreen();
void showLearnModePlayingScreen(String);
void showInstrumentSelectionScreen();


/********************************************
 *            CUSTOM LIBRARIES              *
 ********************************************/
#include "midi.h"
#include "midi_commands.h"
#include "config.h"
#include "utilities.h"
#include "main_menu.h"
#include "instrument_selection.h"
#include "free_mode.h"
#include "listen_mode.h"
#include "learn_mode.h"

File myFile;
File root;

/**
 * Executed once at arduino reset
 * used for some extra configuration
 */
void setup() {
  Serial.begin(MIDI_BAUDS);

  //Initializing the SD card
  if (!SD.begin(PIN_CS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done!");
  
  // Register custom characters for the LCD
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.createChar(0, rigthArrow);
  lcd.createChar(1, leftArrow);
  lcd.createChar(2, downArrow);
  lcd.createChar(3, upArrow);
  
  goToScreen(SCREEN_MAIN_MENU, "");

  // getMelodyFromFile("ALEGRIA.TXT");
}


/**
 * Executed every time in a forever loop after setup() completes
 * wont be used
 */
void loop() {
  
}

void test() {
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(PIN_CS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("alegria.txt");
  if (myFile) {
    Serial.println("alegria.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening alegria.txt");
  }
}

void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

void test2(){
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(PIN_CS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  root = SD.open("/");

  printDirectory(root, 0);

  Serial.println("done!");
  
}
