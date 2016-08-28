/**
 * Draw a menu and the selector icon, including arrows 
 * if the menu have more items not seen in screen
 * 
 * @param menu the menu to display
 * @param menuSize the number of  elements the menu have
 * @param currentPosition the actual selector position in the menu
 */
void refreshScreen(char *menu[],byte menuSize, byte currentPosition) {

  // Real wor position of selected item in screen
  byte realPosition = currentPosition % LCD_ROWS;
  // First element to be printed  
  byte first = currentPosition - realPosition;
  
  lcd.clear();

  // Print the menu
  for (byte i = 0; i < LCD_ROWS && first + i < menuSize; i++) {
    lcd.setCursor(1, i);
    lcd.print(menu[first + i]);
  }

  // write the selector arrow
  lcd.setCursor(0, realPosition);
  lcd.write((byte)0);

  // up arrow
  if (currentPosition >= LCD_ROWS) {
    lcd.setCursor(0, LCD_COLS - 1);
    lcd.write((byte)3);
  }
  //down arrow
  if (first + LCD_ROWS < menuSize) {
    lcd.setCursor(LCD_ROWS - 1, LCD_COLS - 1);
    lcd.write((byte)2);
  }
  
}

/**
 * Go to the screen passed
 * 
 * @param screen the screen to go
 * @param extra  string for any extra things that need to be passed between screens
 */
void goToScreen(byte screen, String extra) {

  switch(screen) {
    case SCREEN_MAIN_MENU:
            showMainMenuScreen();
            break;
    case SCREEN_FREE_MODE:
            showFreeModeScreen();
            break;
    case SCREEN_LISTEN_MODE_SELECTION:
            showListenModeSelectionScreen();
            break;
    case SCREEN_LISTEN_MODE_PLAYING:
            showListenModePlayingScreen(extra);
            break;
    case SCREEN_LEARN_MODE_SELECTION:
            showLearnModeSelectionScreen();
            break;
    case SCREEN_LEARN_MODE_PLAYING:
            showLearnModePlayingScreen(extra);
            break;
    case SCREEN_INSTRUMENT_SELECTION:
            showInstrumentSelectionScreen();
            break;
  }
}


