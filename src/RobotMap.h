#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {
public:
	// Climber subsystem
	static std::shared_ptr<SpeedController> winchMotor;
	static std::shared_ptr<Servo> rachetServo;

	// Drivetrain subsystem
	static std::shared_ptr<AnalogGyro> gyro;
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

	// Ultrasonic subsystem
	static std::shared_ptr<Ultrasonic> ultrasonic;

	static void init();
	static void reset();
};

#endif  // ROBOTMAP_H
