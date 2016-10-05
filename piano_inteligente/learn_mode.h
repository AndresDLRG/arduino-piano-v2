
void showLearnModeSelectionScreen(){

  int menuSize = getCountFilesFromSD();
  char** menu = getFilesFromSdAsMenu(menuSize);

  // Draw my menu once, selector at first element
  refreshScreen(menu, menuSize, 0);
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
          refreshScreen(menu, menuSize, selector);
      }    
    } else if (key == '8') { // down
      if(selector < menuSize - 1) { // not taking over positive selection
          selector++;
          refreshScreen(menu, menuSize, selector);
      } 
    } else if (key == '6') { // select
      // Check the selected item
      showLearnModePlayingScreen(menu[selector]);

      // When the next screen return
      selector = 0;
      refreshScreen(menu, menuSize, 0);
    } else if (key == '4') {//back
      return;
    }
  // Do other things not related to menu

  // So the arduino wont over proccess
  delay(50);
  }
}

void showLearnModePlayingScreen(String melody) {
  Melody myMelody = getMelodyFromFile(melody);
  int responseCode;
  
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("APRENDIENDO:");
  lcd.setCursor(1,1);
  lcd.print(melody);
  lcd.setCursor(1, 3);
  lcd.write((byte)1);
  lcd.print("PARA REGRESAR");
  
  responseCode = learn(&myMelody);;
  
  if (responseCode == 1) { // melody learned successfully
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("FELICIDADES");
    lcd.setCursor(3, 2);
    lcd.print("LO HAS LOGRADO");
    delay(5000);
  } 
    
}

