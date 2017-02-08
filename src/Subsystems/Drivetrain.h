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
	std::shared_ptr<SpeedController> drivetrainSpeedController1;
	std::shared_ptr<SpeedController> drivetrainSpeedController2;
	std::shared_ptr<RobotDrive> robotDrive;

public:
	Drivetrain();
	void InitDefaultCommand();
	void ArcadeDrive(double, double);
	void Stop();
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
