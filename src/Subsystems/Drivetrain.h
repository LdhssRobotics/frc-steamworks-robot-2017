/*
 * Drivetrain.h
 *
 *  Created on: Feb 7, 2017
 *      Author: programmer
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drivetrain: public Subsystem {
public:
	std::shared_ptr<AnalogGyro> gyro;
	std::shared_ptr<Ultrasonic> ultrasonic;
	std::shared_ptr<Encoder> driveEncoder;
	std::shared_ptr<SpeedController> leftDrive;
	std::shared_ptr<SpeedController> rightDrive;
	std::shared_ptr<RobotDrive> robotDrive;

	Drivetrain();
	void InitDefaultCommand();
	void ArcadeDrive(double, double);
	void Stop();
	void Reset();
	double GetHeading();
	void Log();
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
