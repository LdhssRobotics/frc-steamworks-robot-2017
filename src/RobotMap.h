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
	static std::shared_ptr<AnalogGyro> gyro;
	static std::shared_ptr<frc::Ultrasonic> ultrasonic;
	static std::shared_ptr<Encoder> driveEncoder;
	static std::shared_ptr<SpeedController> frontLeftDrive;
	static std::shared_ptr<SpeedController> backLeftDrive;
	static std::shared_ptr<SpeedController> frontRightDrive;
	static std::shared_ptr<SpeedController> backRightDrive;
	static std::shared_ptr<RobotDrive> robotDrive;

	// Gear subsystem
	static std::shared_ptr<Encoder> gearEncoder;
	static std::shared_ptr<SpeedController> gearMotor;
	static std::shared_ptr<DigitalInput> gearLimitSwitch;

	// Shooter subsystem
	static std::shared_ptr<SpeedController> flywheelMotor1;
	static std::shared_ptr<SpeedController> flywheelMotor2;
	static std::shared_ptr<DigitalInput> shooterLeftLimitSwitch;
	static std::shared_ptr<DigitalInput> shooterRightLimitSwitch;
	static std::shared_ptr<SpeedController> shooterHorizontalMotor;
	static std::shared_ptr<Servo> shooterFlap;
	static std::shared_ptr<Servo> ballStopper;
	static std::shared_ptr<Encoder> flywheelEncoder1;
	static std::shared_ptr<Encoder> flywheelEncoder2;

	static void init();
	static void reset();
};

#endif  // ROBOTMAP_H
