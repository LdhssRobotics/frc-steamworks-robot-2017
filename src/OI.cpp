#include "OI.h"
#include "Commands/ClimbRope.h"
#include "Commands/PlaceGear.h"
#include "Commands/SetHeading.h"
#include "WPILib.h"

OI::OI() {
	driveStick.reset(new Joystick(0));
	recoveryStick.reset(new Joystick(1));

	// Drive Stick Buttons
	aButtonD = new JoystickButton(driveStick.get(), 1);
	bButtonD = new JoystickButton(driveStick.get(), 2);
	xButtonD = new JoystickButton(driveStick.get(), 3);
	yButtonD = new JoystickButton(driveStick.get(), 4);
	leftBumperButtonD = new JoystickButton(driveStick.get(), 5);
	rightBumperButtonD = new JoystickButton(driveStick.get(), 6);
	selectButtonD = new JoystickButton(driveStick.get(), 7);
	startButtonD = new JoystickButton(driveStick.get(), 8);
	leftStickButtonD = new JoystickButton(driveStick.get(), 9);
	rightStickButtonD = new JoystickButton(driveStick.get(), 1);

	// Recovery Stick Buttons
	aButtonR = new JoystickButton(recoveryStick.get(), 1);
	bButtonR = new JoystickButton(recoveryStick.get(), 2);
	xButtonR = new JoystickButton(recoveryStick.get(), 3);
	yButtonR = new JoystickButton(recoveryStick.get(), 4);
	leftBumperButtonR = new JoystickButton(recoveryStick.get(), 5);
	rightBumperButtonR = new JoystickButton(recoveryStick.get(), 6);
	selectButtonR = new JoystickButton(recoveryStick.get(), 7);
	startButtonR = new JoystickButton(recoveryStick.get(), 8);
	leftStickButtonR = new JoystickButton(recoveryStick.get(), 9);
	rightStickButtonR = new JoystickButton(recoveryStick.get(), 1);

	// Assigning Commands to Buttons
	// Drive Stick Controls
	startButtonD->ToggleWhenPressed(new ClimbRope());

	// Recovery Stick Controls
	aButtonR->WhenPressed(new PlaceGear());
	bButtonR->WhenPressed(new SetHeading(45));
	xButtonR->WhenPressed(new SetHeading(180));
}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}

std::shared_ptr<Joystick> OI::getRecoveryStick() {
	return recoveryStick;
}
