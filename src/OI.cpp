#include "OI.h"
#include "WPILib.h"

#include "Commands/ClimbRope.h"
#include "Commands/ReverseRope.h"
#include "Commands/GoBackGear.h"
#include "Commands/PlaceGear.h"
#include "Commands/ToggleFrontEnd.h"

OI::OI() {
	driveStick.reset(new Joystick(0));

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

	// Assigning Commands to Buttons

	// Drive Stick Controls
	startButtonD->ToggleWhenPressed(new ClimbRope()); // Climb the rope
	selectButtonD->ToggleWhenPressed(new ReverseRope()); // Reverses the rope mechanism (to bring the robot down after a match)
	aButtonD->WhenPressed(new PlaceGear()); // Place gear on peg
	bButtonD->WhenPressed(new GoBackGear()); // Return to original position
	xButtonD->ToggleWhenPressed(new ToggleFrontEnd());
	// Left bumper button reduces base speed while held
	// Right bumper button reduces turn speed while held
	// Y-axis of left joystick controls base speed
	// X-axis of right joystick controls turn speed
}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}
