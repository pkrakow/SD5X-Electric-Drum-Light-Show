SD5X-Electric-Drum-Light-Show
=============================

This repository is filled with love and kindness and arduino code that drives EL lights in sync with drum hits on a Simmons SD5X electric drum kit.  This was a little christmas project I whipped up for my kids.

You can see a video of the kit with the lights here: http://www.youtube.com/watch?v=O_wOILqH7EU

This sketch requires the Arduino Midi Library and a custom El Escudo Extended library that I, err, created.  I've included the Midi library in this repository.  You can find the official version here: http://playground.arduino.cc/Main/MIDILibrary.  You can find the El Escudo Extended library here: https://github.com/pkrakow/El-Escudo-Extended.  It should be in this repository, but I couldn't figure out why my Github commits were failing on the 2 files in that library, so I quit and posted them to a new repository.

The system is built around an Arduino Uno (http://arduino.cc/en/Main/arduinoBoardUno), a sparkfun El Escudo (https://www.sparkfun.com/products/retired/9259), and a sparkfun midi shield (https://www.sparkfun.com/products/9595).

I stacked the midi shield on top of the El Escudo, and removed the D6 and D7 pins from the midi shield (so the LEDs wouldn't affect the EL Wires).  Ping me if you have any questions on how to wire everything up.  

Also, I tried mounting the EL Wires directly on the SD5X kit ('cause that would have been rad), but the EL Wires interfered with the drum triggers in funky ways (sensitivity was messed up on the hi-hat, Tom1 triggered the Hi-hat and the snare, etc.).  All solvable problems, but my kids didn't care so I just went for the random spaghetti monster in the middle of the kit (http://en.wikipedia.org/wiki/Flying_Spaghetti_Monster).
