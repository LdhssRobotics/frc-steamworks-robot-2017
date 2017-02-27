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
#include "OI.h"


Drivetrain::Drivetrain() : Subsystem("Drivetrain"){
	gyro = RobotMap::gyro;
	ultrasonic = RobotMap::ultrasonic;
	driveEncoder = RobotMap::driveEncoder;
	leftDrive = RobotMap::leftDrive;
	rightDrive = RobotMap::rightDrive;
	robotDrive = RobotMap::robotDrive;
	gyro = RobotMap::gyro;
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

void Drivetrain::Reset() {
	gyro->Reset();
}

double Drivetrain::GetHeading()
{
	return gyro->GetAngle();
}

void Drivetrain::Log()
{
	SmartDashboard::PutNumber("RobotHeadingInDegrees", GetHeading());
}
