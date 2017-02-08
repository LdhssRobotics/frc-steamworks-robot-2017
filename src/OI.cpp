#include "OI.h"

OI::OI() {
	joystick1.reset(new Joystick(0));

	aButton.reset(new JoystickButton(joystick1.get(), 0));
	bButton.reset(new JoystickButton(joystick1.get(), 1));
	xButton.reset(new JoystickButton(joystick1.get(), 2));
	yButton.reset(new JoystickButton(joystick1.get(), 3));
	leftBumperButton.reset(new JoystickButton(joystick1.get(), 4));
	rightBumperButton.reset(new JoystickButton(joystick1.get(), 5));
	selectButton.reset(new JoystickButton(joystick1.get(), 6));
	startButton.reset(new JoystickButton(joystick1.get(), 7));
	leftStickButton.reset(new JoystickButton(joystick1.get(), 8));
	rightStickButton.reset(new JoystickButton(joystick1.get(), 9));
}

std::shared_ptr<Joystick> OI::getJoystick() {
	return joystick1;
}
