#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {
public:
	// Ball intake subsystem
	static std::shared_ptr<SpeedController> ballIntakeMotor;
	static std::shared_ptr<Servo> ballIntakeServo;

	// Climber subsystem
	static std::shared_ptr<SpeedController> winchMotor;
	static std::shared_ptr<Servo> ratchetServo;

	// Drivetrain subsystem
	static std::shared_ptr<SpeedController> drivetrainSpeedController1;
	static std::shared_ptr<SpeedController> drivetrainSpeedController2;
	static std::shared_ptr<RobotDrive> robotDrive;

	// Shooter subsystem
	static std::shared_ptr<SpeedController> shooterHorizontalAdjust;
	static std::shared_ptr<SpeedController> shooterFlywheelVictor;
	static std::shared_ptr<DigitalInput> shooterLimitSwitch1;
	static std::shared_ptr<DigitalInput> shooterLimitSwitch2;
	static std::shared_ptr<Servo> shooterVerticalAdjust;
	static std::shared_ptr<Servo> shooterBallStopper;

	static void init();
};

#endif  // ROBOTMAP_H
