/*
 * Drivetrain.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: programmer
 */

#include "Drivetrain.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystick.h"
#include "../Robot.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain"){
	drivetrainSpeedController1 = RobotMap::drivetrainSpeedController1;
	drivetrainSpeedController2 = RobotMap::drivetrainSpeedController2;
	robotDrive = RobotMap::robotDrive;
}

void Drivetrain::InitDefaultCommand(){
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::ArcadeDrive(double speed, double turn){
	robotDrive->ArcadeDrive(speed, turn);
}

void Drivetrain::Stop(){
	ArcadeDrive(0, 0);
}
