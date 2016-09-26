/**
 * Shows tha main menu and direct to others menus
 */
void showMainMenuScreen(){

  // Draw my menu once, selector at first element
  refreshScreen(MENU_MAIN, MENU_MAIN_SIZE, 0);
  // Current element selected
  int selector = 0;
  // For reading the keypad
  char key;
  
  //
  while(true) {
    // Get if a key is pressed
    key = keypad.getKey();
    
    if (key == '2') { // up
      if(selector > 0) { // not taking negative selection
          selector--;
          refreshScreen(MENU_MAIN, MENU_MAIN_SIZE, selector);
      }    
    } else if (key == '8') { // down
      if(selector < MENU_MAIN_SIZE - 1) { // not taking over positive selection
          selector++;
          refreshScreen(MENU_MAIN, MENU_MAIN_SIZE, selector);
      } 
    } else if (key == '6') { // select
      // Check the selected item
      switch(selector) {
        case 0: goToScreen(SCREEN_FREE_MODE, "");
                break;
        case 1: goToScreen(SCREEN_LISTEN_MODE_SELECTION, "");
                break;
        case 2: goToScreen(SCREEN_LEARN_MODE_SELECTION, "");
                break;
        case 3: goToScreen(SCREEN_INSTRUMENT_SELECTION, "");
                break;
      }

      // When the next screen return
      selector = 0;
      refreshScreen(MENU_MAIN, MENU_MAIN_SIZE, 0);
    }

  // Do other things not related to menu

  // So the arduino wont over proccess
  delay(50);
  }
}

