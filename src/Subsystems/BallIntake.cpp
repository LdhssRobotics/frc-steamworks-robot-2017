/*
 * BallIntake.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: programmer
 */

#include "BallIntake.h"
#include "../Robot.h"
#include "../RobotMap.h"

BallIntake::BallIntake() : Subsystem("BallIntake") {
	ballIntakeMotor = RobotMap::ballIntakeMotor;
}

void BallIntake::Reset() {
	Stop();
}
void BallIntake::SetIntakeSpeed(float speed){
	ballIntakeMotor->Set(speed);
}

void BallIntake::ReverseIntakeSpeed(float speed){
	ballIntakeMotor->Set(-speed);
}

void BallIntake::Stop(){
	ballIntakeMotor->Set(0);
}

void BallIntake::Log(float intakeSpeed) {
	SmartDashboard::PutNumber("Ball intake speed:", intakeSpeed);
}
