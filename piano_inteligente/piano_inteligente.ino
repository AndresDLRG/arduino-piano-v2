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
 *            PUBLIC LIBRARIES              *
 ********************************************/
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

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


/**
 * Executed once at arduino reset
 * used for some extra configuration
 */
void setup() {
  //Regsiter custom characters for the LCD
  lcd.createChar(0, rigthArrow);
  lcd.createChar(1, leftArrow);
  lcd.createChar(2, downArrow);
  lcd.createChar(3, upArrow);

  Serial.begin(MIDI_BAUDS);
  
  goToScreen(SCREEN_MAIN_MENU, "");
}


/**
 * Executed every time in a forever loop after setup() completes
 * wont be used
 */
void loop() {
  
}
