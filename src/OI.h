#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	std::shared_ptr<Joystick> driveStick;

	// Drive Stick Buttons
	JoystickButton *aButtonD;
	JoystickButton *bButtonD;
	JoystickButton *xButtonD;
	JoystickButton *yButtonD;
	JoystickButton *leftBumperButtonD;
	JoystickButton *rightBumperButtonD;
	JoystickButton *selectButtonD;
	JoystickButton *startButtonD;
	JoystickButton *leftStickButtonD;

	// Axes
	static const int LEFT_X_AXIS = 0;
	static const int LEFT_Y_AXIS = 1;
	static const int LEFT_TRIGGER_AXIS = 2;
	static const int RIGHT_TRIGGER_AXIS = 3;
	static const int RIGHT_X_AXIS = 4;
	static const int RIGHT_Y_AXIS = 5;

	OI();

	std::shared_ptr<Joystick> getDriveStick();
};

#endif  // OI_H
