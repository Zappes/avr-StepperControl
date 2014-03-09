StepperControl Controls a Stepper With a Controller
===================================================

What Is this?
-------------
This little project makes a stepper motor that has been salvaged from a CD burner step. I won't go into details here - you find everything about those motors on the web, just google for something like "dvd stepper motor avr". You might also want to look at this: http://homepage.cs.uiowa.edu/~jones/step/

![Image of StepperControl](https://github.com/Zappes/avr-StepperControl/blob/master/Fritzing/StepperControl_photo.jpg?raw=true)

Please keep in mind that this is just a dirty prototype that I came up with under the shower. You probably want to have more voltage for real applications and driving the motor from the output pins' current probably isn't the brightest idea, either. After the project was completed, I actually read that my approach was crap and one should use a "dual full H-bridge" for this task. I found a nice little explanation here: http://www.kerrywong.com/2010/03/22/a-simple-dual-h-bridge/

Why I put this on Github even though it's crap? Because I had fun figuring this approach out and because it's a starting point. If you have no clue about steppers (like me when I started this), it might give you some insights. At the very least you can learn how not to do this. ;)

Hardware
--------
The "Fritzing" subdirectory of the project contains schematics and a list of materials. The main ingredients are an ATmega328 controller (the one you also find in an Arduino UNO) clocked at 16MHz, the stepper motor from an old DVD burner, some diodes, some transistors, some resistors and some wire. Nothing too fancy.

Functions
---------
The thing steps forward for a while. Then it steps backward. If you want more, toy around with the main routine.
