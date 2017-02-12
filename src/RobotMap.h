#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "Robot.h"
#include "LiveWindow/LiveWindow.h"

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
	static std::shared_ptr<SpeedController> gearMotor;
	static std::shared_ptr<DigitalInput> gearLimitSwitch;

	// Shooter subsystem
	static std::shared_ptr<SpeedController> flywheelMotor;
	static std::shared_ptr<DigitalInput> shooterLeftLimitSwitch;
	static std::shared_ptr<DigitalInput> shooterRightLimitSwitch;
	static std::shared_ptr<SpeedController> shooterHorizontalAdjust;
	static std::shared_ptr<Servo> shooterVerticalAdjust;
	static std::shared_ptr<Servo> ballStopper;
	static std::shared_ptr<Encoder> flywheelEncoder;

	static void init(); // Initializes all the speed controllers and sensors
	static void reset(); // Resets all the subsystems
};

#endif  // ROBOTMAP_H
