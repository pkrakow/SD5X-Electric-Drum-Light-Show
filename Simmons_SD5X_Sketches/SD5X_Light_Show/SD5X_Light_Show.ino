/* 
* SD5X_Light_Show - Arduino sketch that controls electroluminescent lights so they to go on and off
* in synchronization (or syncopation if you're a fancy player) with drum hits on the Simmons SD5X 
* electronic drum kit.
* 
* Created by Paul Krakow, December 24, 2013 for his lucky kids.
* Released into the public domain.
* 
* This program is dependent on version 3.2 of the the MIDI.h library to handle MIDI commands.  
* You can find the MIDI library here: http://playground.arduino.cc/Main/MIDILibrary
* 
* This program is also dependent on the El_Escudo_Extended.h library to control the EL Wires on the 
* http://www.sparkfun.com EL Escudo board.
* You can find the EL Escudo Extended Library here: https://github.com/pkrakow/EL-Escudo-Extended
* 
* The Simmons SD5X uses the following MIDI Note Names
*   NO.  NAME          NOTE    New_EL_Wire
*   8    Hi-Hat Close  42      A
*   9    Hi-Hat Open   46      A
*   10   Hi-Hat Pedal  44      A
*   1    Crash1        49      B
*   5    Ride          51      C
*   7    Snare         38      D
*   2    Tom1          48      E
*   3    Tom2          45      F
*   4    Tom3          43      G
*   6    Kick          36      H
*
*/

//The EL_Escudo library uses letters A-H to reference each EL string.
//Each EL string output has a corresponding label on the EL Escudo shield.
#include <EL_Escudo_Extended.h>
#include <MIDI.h>


void setup() {
  // Define a variable for EL Wire commands and make sure all EL wires are turned off

  EL.all_off();
  
  // Initiate MIDI communications, listen to all channels
  MIDI.begin(MIDI_CHANNEL_OMNI);    
  
  // Connect the HandleNoteOn function to the library, so it is called upon reception of a NoteOn.
  MIDI.setHandleNoteOn(HandleNoteOn);  // Put only the name of the function
     
}


void loop() {
  // Call MIDI.read the fastest you can for real-time performance.
  MIDI.read();
  
  // There is no need to check if there are messages incoming if they are bound to a Callback function.
}



void HandleNoteOn(byte channel, byte note, byte velocity) { 
  // Try to keep your callbacks short (no delays ect) as the contrary would slow down the loop()
  // and have a bad impact on real-time performance.
  
  // When you receive a Note On, turn on the EL Wire for that note.
  switch (note) {
   case  42: // Hi-Hat triggers EL Wire A
   case  46:
   case  44:
     ManageELWires(A, velocity);  
     break; 
   case  49: // Crash1 triggers EL Wire B
     ManageELWires(B, velocity);   
     break;
   case  51: // Ride triggers EL Wire C
     ManageELWires(C, velocity);  
     break; 
   case  38: // Snare triggers EL Wire D
     ManageELWires(D, velocity);   
     break;
   case  48: // Tom1 triggers EL Wire E
     ManageELWires(E, velocity);  
     break;
   case  45: // Tom2 triggers EL Wire F
     ManageELWires(7, velocity);     // Getting a weird compiler error with 'F' so hard coding 7
     break;
   case  43: // Tom3 triggers EL Wire G
     ManageELWires(G, velocity);   
     break;
   case  36: // Kick triggers EL Wire H
     ManageELWires(H, velocity);   
     break;
  }

  Serial.flush();  // Clear the buffer in case other drum hits occured when the EL wire was flashing
}


void ManageELWires(int New_EL_Wire, byte velocity) { 
  // Flash the EL Wire quickly
  if (velocity > 20) {
    EL.on(New_EL_Wire);
    EL.variable_fade_out(New_EL_Wire, 1);
  }
}
