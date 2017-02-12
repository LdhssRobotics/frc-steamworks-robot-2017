#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {
public:
	// Ball intake subsystem
	static std::shared_ptr<SpeedController> ballIntakeMotor;

	// Climber subsystem
	static std::shared_ptr<SpeedController> winchMotor;
	static std::shared_ptr<Servo> rachetServo;

	// Drivetrain subsystem
	static std::shared_ptr<SpeedController> leftDrive;
	static std::shared_ptr<SpeedController> rightDrive;
	static std::shared_ptr<RobotDrive> robotDrive;

	// Gear subsystem
	static std::shared_ptr<Encoder> gearEncoder;
	static std::shared_ptr<Servo> gearServo;

	// Shooter subsystem
	static std::shared_ptr<SpeedController> flywheelMotor;
	static std::shared_ptr<DigitalInput> shooterLeftLimitSwitch;
	static std::shared_ptr<DigitalInput> shooterRightLimitSwitch;
	static std::shared_ptr<SpeedController> shooterHorizontalAdjust;
	static std::shared_ptr<Servo> shooterVerticalAdjust;
	static std::shared_ptr<Servo> ballStopper;
	static std::shared_ptr<Encoder> flywheelEncoder;

	static void init();
	static void reset();
};

#endif  // ROBOTMAP_H
