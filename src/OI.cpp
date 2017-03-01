#include "OI.h"
#include "WPILib.h"

#include "Commands/ClimbRope.h"
#include "Commands/SetHeading.h"
#include "Commands/GearMechanism.h"
#include "Commands/ManualShoot.h"
#include "Commands/ResetShooter.h"
#include "Commands/ToggleBallIntake.h"
  
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
	rightBumperButtonD->WhileHeld(new ManualShoot());
	rightBumperButtonD->WhenReleased(new ResetShooter());

	// Recovery Stick Controls
	aButtonR->WhenPressed(new GearMechanism());
	xButtonR->ToggleWhenPressed(new ToggleBallIntake(ToggleBallIntake::INTAKE_SPEED));
	yButtonR->ToggleWhenPressed(new ToggleBallIntake(ToggleBallIntake::REVERSEINTAKE_SPEED));
}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}

std::shared_ptr<Joystick> OI::getRecoveryStick() {
	return recoveryStick;
}
