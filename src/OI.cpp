#include "OI.h"
#include "Commands/ClimbRope.h"
#include "WPILib.h"

OI::OI() {
	joystick.reset(new Joystick(0));

	aButton = new JoystickButton(joystick.get(), 1);
	bButton = new JoystickButton(joystick.get(), 2);
	xButton = new JoystickButton(joystick.get(), 3);
	yButton = new JoystickButton(joystick.get(), 4);
	leftBumperButton = new JoystickButton(joystick.get(), 5);
	rightBumperButton = new JoystickButton(joystick.get(), 6);
	selectButton = new JoystickButton(joystick.get(), 7);
	startButton = new JoystickButton(joystick.get(), 8);
	leftStickButton = new JoystickButton(joystick.get(), 9);
	rightStickButton = new JoystickButton(joystick.get(), 1);

	startButton->ToggleWhenPressed(new ClimbRope());
}

std::shared_ptr<Joystick> OI::getJoystick() {
	return joystick;
}
