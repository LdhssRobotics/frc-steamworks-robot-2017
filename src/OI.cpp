#include "OI.h"
#include "WPILib.h"

#include "Commands/ClimbRope.h"
#include "Commands/ReverseRope.h"
#include "Commands/SetHeading.h"
#include "Commands/GearMechanism.h"
#include "Commands/ManualShoot.h"
#include "Commands/ResetShooter.h"
#include "Commands/ToggleBallIntake.h"
#include "Commands/GoBackGear.h"
#include "Commands/PlaceGear.h"

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
	startButtonD->ToggleWhenPressed(new ClimbRope()); // Climb the rope (full speed)
	xButtonD->ToggleWhenPressed(new ReverseRope()); // Reverses the rope mechanism (to bring the robot down after a match)
	//rightBumperButtonD->WhileHeld(new ManualShoot());
	//rightBumperButtonD->WhenReleased(new ResetShooter());
	aButtonD->WhenPressed(new PlaceGear()); // Place gear on peg
	bButtonD->WhenPressed(new GoBackGear()); // Return to original position

	// Recovery Stick Controls
	bButtonR->ToggleWhenPressed(new ToggleBallIntake(ToggleBallIntake::INTAKE_SPEED));
	xButtonR->ToggleWhenPressed(new ToggleBallIntake(ToggleBallIntake::REVERSE_INTAKE_SPEED));
}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}

std::shared_ptr<Joystick> OI::getRecoveryStick() {
	return recoveryStick;
}
