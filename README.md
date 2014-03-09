StepperControl Controls a Stepper With a Controller
===================================================

What Is this?
-------------
This little project makes a stepper motor that has been salvaged from a CD burner step. I won't go into details here - you find everything about those motors on the web, just google for something like "dvd stepper motor avr". You might also want to look at this: http://homepage.cs.uiowa.edu/~jones/step/

![Image of StepperControl](https://github.com/Zappes/avr-StepperControl/blob/master/Fritzing/StepperControl_photo.jpg?raw=true)

Please keep in mind that this is just a dirty prototype that I came up with under the shower. You probably want to have more voltage for real applications and driving the motor from the output pins' current probably isn't the brightest idea, either. After the project was completed, I actually read that my approach was crap and one should use a "dual full H-bridge" for this task. I found a nice little explanation here: http://www.kerrywong.com/2010/03/22/a-simple-dual-h-bridge/

One question you might want to ask when looking at my design is why I didn't use the ATmega's ports as current sinks instead of doing all that stuff with the transistors. [Pulsar256](https://github.com/pulsar256) actually asked, and the answer has two parts:

* At first I did exactly that. No transistors, no diodes, coils wired up directly to the muc's pins. It didn't work, so I tried to build something that would direct the current to common ground instead of pushing it into the controller. The funny thing is that it would probably have worked, but I had a totally unrelated bug in the controller code ... After I fixed that, I had already wired up the more complicated thing you see above, and I didn't want to remove all that nicely laid out electronics stuff again.
* I had planned to get the current from an external 12V supply instead of the muc's pins using some pnp transistors. Before I had a chance of implementing that plan, I read about [H-bridges](http://mcmanis.com/chuck/robotics/tutorial/h-bridge/bjt-bridge.html) and I realized that I was about to re-invent a very basic circuit that practically everybody but me seemed to know already. I decided not to do more work on the circuit. Instead I just documented what I had done so far, put everything up on Github and ripped the parts from the breadboard again.

Why I put this on Github even though it's crap? Because I had fun figuring this approach out and because it's a starting point. If you have no clue about steppers and H-bridges and whatever(like me when I started this), it might give you some insights. At the very least you can learn how *not* to do this. ;)

Hardware
--------
The "Fritzing" subdirectory of the project contains schematics and a list of materials. The main ingredients are an ATmega328 controller (the one you also find in an Arduino UNO) clocked at 16MHz, the stepper motor from an old DVD burner, some diodes, some transistors, some resistors and some wire. Nothing too fancy.

Functions
---------
The thing steps forward for a while. Then it steps backward. If you want more, toy around with the main routine.
