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
private:
	std::shared_ptr<AnalogGyro> gyro;
	std::shared_ptr<Encoder> driveEncoder;
	std::shared_ptr<RobotDrive> robotDrive;

public:
	// Must be public to be used in SetHeading
	std::shared_ptr<SpeedController> backLeftDrive;
	std::shared_ptr<SpeedController> backRightDrive;
	std::shared_ptr<SpeedController> frontLeftDrive;
	std::shared_ptr<SpeedController> frontRightDrive;

	Drivetrain();
	void InitDefaultCommand();
	void ArcadeDrive(double, double);
	void Stop();
	void Reset();
	double GetHeading();
	void Log();
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
