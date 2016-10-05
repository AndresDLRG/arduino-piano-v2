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
    lcd.setCursor(LCD_COLS - 1, 0);
    lcd.write((byte)3);
  }
  //down arrow
  if (first + LCD_ROWS < menuSize) {
    lcd.setCursor(LCD_COLS - 1, LCD_ROWS - 1);
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

/**
 * Plays a melody without human interaction, can not be interrupted,
 * if interrupted is needed make your own function
 * 
 * @param melody the melody to play
 */
void reproducirCancion(struct Melody melody) {
  for (uint8_t i = 0; i < melody.size; i++) {
    midiNoteOn(melody.notes[i], MIDI_VOLUME);
    delay(melody.times[i]);
    midiNoteOff(melody.notes[i], MIDI_VOLUME);
    delay(melody.rests[i]);
  }
}

/**
 * Return the pin associated with ne midi note passed
 * 
 * @param note the note for which the pin will be returned
 * @return the pin associated with the note
 */
byte getPinForNote(byte note) {
  switch(note % PINS_PIANO_KEY_SIZE) {
    case 0: return PIN_DO;
    case 1: return PIN_DO_;
    case 2: return PIN_RE;
    case 3: return PIN_RE_;
    case 4: return PIN_MI;
    case 5: return PIN_FA;
    case 6: return PIN_FA_;
    case 7: return PIN_SOL;
    case 8: return PIN_SOL_;
    case 9: return PIN_LA;
    case 10: return PIN_LA_;
    case 11: return PIN_SI;
  }
}

/**
 * Creates a menu holding the names of files from the SD
 * 
 * @param fileCount the number of files that gonna be read
 */
char**  getFilesFromSdAsMenu(int fileCount){
  char ** menu = (char**)malloc(fileCount * sizeof(char*));
  File root = SD.open("/");
  int i = 0;
  
  while (true) {
    File entry =  root.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    menu[i] = (char*)malloc(15 * sizeof(char));
    menu[i] = strdup(entry.name());
    i++;
    entry.close();
  }
  root.close();
  return menu;
}

/**
 * Gets the number of files that are in the root of the SD
 */
int getCountFilesFromSD() {
  File root = SD.open("/");

  int i = 0;
  while (true) {
    File entry =  root.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    i++;
    entry.close();
  }
  root.close();
  return i;
}

/**
 * Parse a file into a Melody struct
 * 
 * @param file the name of the file to open
 */
struct Melody getMelodyFromFile(String file) {
  File myFile;
  struct Melody myMelody;
  char c;
  int previousLine = 0;
  int currentLine = 0;
  String line = "";
  int cont = 0;
  
  myFile = SD.open(file);
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      if (currentLine == 2) { // notes
        c = myFile.read();
        if (c == '\n') {
          if (line != "") {
            myMelody.notes[cont++] = line.toInt();
            line = "";
          }
          currentLine++;
        } else if (c == ','){
          myMelody.notes[cont++] = line.toInt();
          line = "";
        } else {
          line += c;
        }
      } else if (currentLine == 3) { // times
        c = myFile.read();
        if (c == '\n') {
          if (line != "") {
            myMelody.times[cont++] = line.toInt();
            line = "";
          }
          currentLine++;
        } else if (c == ','){
          myMelody.times[cont++] = line.toInt();
          line = "";
        } else {
          line += c;
        }
      } else if (currentLine == 4) { // rests
        c = myFile.read();
        if (c == '\n') {
          if (line != "") {
            myMelody.rests[cont++] = line.toInt();
            line = "";
          }
          currentLine++;
        } else if (c == ','){
          myMelody.rests[cont++] = line.toInt();
          line = "";
        } else {
          line += c;
        }
      }else { // name or size
        c = myFile.read();
        if (c == '\n') {
          currentLine++;
        } else {
          line += c;
        }
      }
      
      // if lines changed
      if(previousLine != currentLine) {
        previousLine = currentLine;
        switch(currentLine) {
          case 1: line.toCharArray(myMelody.name, 15);
                  Serial.println(myMelody.name);
                  break;
          case 2: myMelody.size = line.toInt();
                  break;
          case 3: cont = 0;
                  break;
          case 4: cont = 0;
                  break;    
          case 5: cont = 0;
                  break;    
        }
        
        line = "";
        cont = 0;
      }
    }
    myMelody.rests[cont++] = line.toInt();
    // close the file:
    myFile.close();
  } else {
    Serial.println("File couldnt be opened");
  }

  return myMelody;
}

/**
 * Prints a melody to Serial
 * 
 * @param melody the melody to print
 */
void printMelody(struct Melody *melody){
  // print my melody for testing purpouses
  Serial.println("Printing my melody after all");
  Serial.print("name: ");
  Serial.println(melody->name);
  Serial.print("size: ");
  Serial.println(melody->size);
  Serial.print("notes: ");
  for (int i = 0; i < melody->size; i++) {
    Serial.print(melody->notes[i]);
    Serial.print(",");
  }
  Serial.println("");
  Serial.print("times: ");
  for (int i = 0; i < melody->size; i++) {
    Serial.print(melody->times[i]);
    Serial.print(",");
  }
  Serial.println("");
  Serial.print("rests: ");
  for (int i = 0; i < melody->size; i++) {
    Serial.print(melody->rests[i]);
    Serial.print(",");
  }
  Serial.println("");
}

/**
 * Plays a melody till the lastNote passed, highligthing the keys of each note
 * 
 * @param melody the melody to play
 * @param lasNote the number of the last note to play
 */
void simonSays(struct Melody *melody, byte lastNote) {
  for (uint8_t i = 0; i < lastNote; i++) {
    midiNoteOn(melody->notes[i], MIDI_VOLUME);
    digitalWrite(getPinForNote(melody->notes[i]), HIGH);
    delay(melody->times[i]);
    midiNoteOff(melody->notes[i], MIDI_VOLUME);
    digitalWrite(getPinForNote(melody->notes[i]), LOW);
    delay(melody->rests[i]);
  }
}

/**
 * Apply learn mode a a melody passed
 * 
 * @param melody the melody to learn
 * @return 1 if successfully completed the melody, other number if not
 */
int learn(struct Melody *melody) {
  uint8_t currentOctave = 0;
  uint8_t maxLevel = melody->size;
  uint8_t currentMaxLevel = 1;
  uint8_t currentLevel = 1;
  uint8_t flag = 0;
  char key;
  uint16_t lastKeys = 0;
  uint16_t currentKeys = 0;

  // print the octave
  lcd.setCursor(LCD_COLS-1,LCD_ROWS-1);
  lcd.print(currentOctave);
  
  // simonSays till last actual
  simonSays(melody, currentMaxLevel);
  
  while(currentMaxLevel <= maxLevel) {
    key = keypad.getKey();
    if (key == '*') { // reduce octave
      if(currentOctave > 0) {
        currentOctave--;
      } else {
        currentOctave = 9;
      }
      lcd.setCursor(LCD_COLS-1,LCD_ROWS-1);
      lcd.print(currentOctave);
    }else if (key == '#') { //aument octave
      if(currentOctave < 9) {
        currentOctave++;
      } else {
        currentOctave = 0;
      }
      lcd.setCursor(LCD_COLS-1,LCD_ROWS-1);
      lcd.print(currentOctave);
    }else if (key == '4') {
      return -1;
    } 

    // Iterate over all my input pins, if the button is pressed the bit representing it become 1, else 0
    for (uint8_t i = 0; i < PINS_PIANO_KEY_SIZE; i++) {
      if (digitalRead(PINS_INPUT[i]) == HIGH) {
        bitWrite(currentKeys, 15 - i, 1);
      } else {
        bitWrite(currentKeys, 15 - i, 0);
      }
    }

    // Iterate over my currentKeys bits
    for (uint8_t i = 0; i < PINS_PIANO_KEY_SIZE; i++) {
      uint8_t myBit = bitRead(currentKeys, 15 - i);
      // if the bit that is used for that pin suffered a state change
      // lets say was 0 the last loop and become 1 or viceversa
      // this ways is for preventing sending to much commands
      if (bitRead(lastKeys, 15 - i) != myBit) {
        // if the bit is 1 turn on the note
        // if is 0 turn off the note
        if(myBit == 1) {
          midiNoteOn(PIN_NOTES[i] + (currentOctave * PINS_PIANO_KEY_SIZE), MIDI_VOLUME);
        } else {
          midiNoteOff(PIN_NOTES[i] + (currentOctave * PINS_PIANO_KEY_SIZE), MIDI_VOLUME);
          
          // detecting if the pressed button was correct
          if(PINS_INPUT[i] == getPinForNote(melody->notes[currentLevel - 1])) {
            currentLevel++;
            if (currentLevel > currentMaxLevel){
              if (currentMaxLevel > maxLevel) {
                // the melody is over
                break;
              }
              currentMaxLevel++;
              currentLevel = 1;
              delay(1000);
              simonSays(melody, currentMaxLevel);
              break;
            }
          } else {
            // if is was a wrong key
            currentLevel = 1;
            delay(500);
            simonSays(melody, currentMaxLevel);
            break;
          }
        }
      }
    }
    // Actualizo mis variables
    lastKeys = currentKeys;
    
    delay(50);
  }
  return 1;
}  


