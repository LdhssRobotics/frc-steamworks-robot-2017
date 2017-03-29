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
	isGearFront = true;

	gyro = RobotMap::gyro;
	driveEncoder = RobotMap::driveEncoder;
	robotDrive = RobotMap::robotDrive;
	frontLeftDrive = RobotMap::frontLeftDrive;
	backLeftDrive = RobotMap::backLeftDrive;
	frontRightDrive = RobotMap::frontRightDrive;
	backRightDrive = RobotMap::backRightDrive;
}

void Drivetrain::InitDefaultCommand(){
	SetDefaultCommand(new DriveWithJoystick());
}

float Drivetrain::GetDistance() {
	return driveEncoder->GetDistance();
}

void Drivetrain::ArcadeDrive(double speed, double turn){
	robotDrive->ArcadeDrive(speed, turn);
}

void Drivetrain::Stop(){
	ArcadeDrive(0, 0);
}

void Drivetrain::Reset() {
	gyro->Reset();
	driveEncoder->Reset();
	Stop();
}

double Drivetrain::GetHeading()
{
	return gyro->GetAngle();
}

void Drivetrain::Log()
{
	SmartDashboard::PutNumber("Robot heading in degrees", GetHeading());
}
