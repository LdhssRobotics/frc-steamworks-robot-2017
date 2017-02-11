#include "OI.h"

OI::OI() {
	joystick1.reset(new Joystick(0));
	
	JoystickButton *aButton = new JoystickButton(joystick1.get(), 1);
	JoystickButton *bButton = new JoystickButton(joystick1.get(), 2);
	JoystickButton *xButton = new JoystickButton(joystick1.get(), 3);
	JoystickButton *yButton = new JoystickButton(joystick1.get(), 4);
	JoystickButton *leftBumperButton = new JoystickButton(joystick1.get(), 5);
	JoystickButton *rightBumperButton = new JoystickButton(joystick1.get(), 6);
	JoystickButton *selectButton = new JoystickButton(joystick1.get(), 7);
	JoystickButton *startButton = new JoystickButton(joystick1.get(), 8);
}

std::shared_ptr<Joystick> OI::getJoystick() {
	return joystick1;
}
