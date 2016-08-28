
/**
 * Sends MIDI commnads via serial connection
 * 
 * @param command also know as status byte, main instruction to pass
 * @param data1 data required for the previous command
 * @param data2 data required for the previous command if neccesary
 */
void midiMessage(uint8_t command, uint8_t data1, uint8_t data2) {
  Serial.write(command);
  Serial.write(data1);
  if (data2 >= 0 ){
    Serial.write(data2);
  }
}

/**
 * Begin playing a note
 * 
 * @param midNote the note to play
 * @param midiVelocity the velocity to play the note (volume)
 */
void midiNoteOn(uint8_t midiNote, uint8_t midiVelocity) {
  if (midiNote  < 128 && midiNote >= 0) {
    midiMessage(MIDI_NOTE_ON, midiNote, midiVelocity);
  }
}

/**
 * Stop playing a note
 * 
 * @param midNote the note to stop playing
 * @param midiVelocity the velocity to stop playing the note (volume)
 */
void midiNoteOff(uint8_t midiNote, uint8_t midiVelocity) {
  if (midiNote  < 128 && midiNote >= 0) {
    midiMessage(MIDI_NOTE_OFF, midiNote, midiVelocity);
  }
}

/**
 * Changes the instrument playing the MIDI notes
 * 
 * @param midiInstrument the instrument for the consequent notes to play 
 */
void midiChangeInstrument(uint8_t midiInstrument) {
  if (midiInstrument < 128 && midiInstrument >= 0) {
    midiMessage(MIDI_CHANGE_INSTRUMENT, midiInstrument, -1);
  }
}

