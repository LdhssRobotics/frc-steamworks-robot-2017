#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	std::shared_ptr<Joystick> joystick1;

	std::shared_ptr<JoystickButton> aButton;
	std::shared_ptr<JoystickButton> bButton;
	std::shared_ptr<JoystickButton> xButton;
	std::shared_ptr<JoystickButton> yButton;
	std::shared_ptr<JoystickButton> leftBumperButton;
	std::shared_ptr<JoystickButton> rightBumperButton;
	std::shared_ptr<JoystickButton> selectButton;
	std::shared_ptr<JoystickButton> startButton;
	std::shared_ptr<JoystickButton> leftStickButton;
	std::shared_ptr<JoystickButton> rightStickButton;

	static const int LEFT_X_AXIS = 0;
	static const int LEFT_Y_AXIS = 1;
	static const int LEFT_TRIGGER_AXIS = 2;
	static const int RIGHT_TRIGGER_AXIS = 3;
	static const int RIGHT_X_AXIS = 4;
	static const int RIGHT_Y_AXIS = 5;

	OI();

	std::shared_ptr<Joystick> getJoystick();
};

#endif  // OI_H
