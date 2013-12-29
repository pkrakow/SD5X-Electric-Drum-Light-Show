SD5X-Electric-Drum-Light-Show
=============================

Arduino code that drives electroluminescent lights in sync with midi notes from a Simmons SD5X electric drum kit.

You can see a video of the kit with the lights here: http://www.youtube.com/watch?v=O_wOILqH7EU

This sketch requires the Arduino Midi Library and a custom El Escudo Extended library that I created.  I've included the Midi library in this repository.  You can find the El Escudo Extended library here: https://github.com/pkrakow/El-Escudo-Extended

The system is built around an Arduino Uno (http://arduino.cc/en/Main/arduinoBoardUno), a sparkfun El Escudo (https://www.sparkfun.com/products/retired/9259), and a sparkfun midi shield (https://www.sparkfun.com/products/9595).

Ping me if you have any questions on how to wire everything up.  I stacked the midi shield on top of the El Escudo, and removed the D6 and D7 pins from the midi shield (so the LEDs wouldn't affect the EL Wires).

Also, I tried mounting the EL Wires directly on the SD5X kit (cause that would have been rad), but the EL Wires interfered with the drum triggers in funky ways (sensitivity was messed up on the hi-hat, Tom1 triggered the Hi-hat and the snare, etc.).  All solvable problems, but my kids didn't care so I just went for the random spaghetti monster in the middle of the kit (http://en.wikipedia.org/wiki/Flying_Spaghetti_Monster).
