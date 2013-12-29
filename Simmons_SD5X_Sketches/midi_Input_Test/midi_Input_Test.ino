// This sketch tests the midi interface between the Simmons SD5X and the Arduino
#include <MIDI.h>

void setup() {
  // Initiate MIDI communications, listen to all channels
  MIDI.begin(MIDI_CHANNEL_OMNI);    
  
  // Connect the HandleNoteOn function to the library, so it is called upon reception of a NoteOn.
  MIDI.setHandleNoteOn(HandleNoteOn);  // Put only the name of the function
  
  // Setup the UNO LED as an output
  pinMode(13, OUTPUT);      
  
  
  // Blinky Test
  for(int i=0; i<5; i++)
  {
    digitalWrite(13, HIGH);   // turns the UNO LED on
    delay(500);
    digitalWrite(13, LOW);    // turns the UNO LED off
    delay(500);
  }
}


void loop() {
  // Call MIDI.read the fastest you can for real-time performance.
  MIDI.read();
  
  // There is no need to check if there are messages incoming if they are bound to a Callback function.
}



void HandleNoteOn(byte channel, byte pitch, byte velocity) { 

  // Do whatever you want when you receive a Note On.
  digitalWrite(13, HIGH);   // turns the UNO LED on
  
  if (velocity == 0) {
    // This acts like a NoteOff.
    digitalWrite(13, LOW);    // turns the UNO LED off
  }

  // Try to keep your callbacks short (no delays ect) as the contrary would slow down the loop()
  // and have a bad impact on real-time performance.
}
