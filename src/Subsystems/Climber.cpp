/*
 * Climber.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: programmer
 */

#include "Climber.h"
#include "../RobotMap.h"
#include "../Robot.h"

Climber::Climber() : Subsystem("Climber") {
	winchMotor = RobotMap::winchMotor;
	rachetServo = RobotMap::rachetServo;
}

void Climber::SetWinchSpeed(float speed) {
	winchMotor->Set(speed);
}

void Climber::SetRachet(float position) {
	rachetServo->Set(position);
}

void Climber::StartClimb() {
	SetWinchSpeed(1);
	SetRachet(0);
}

void Climber::StopClimb() {
	SetWinchSpeed(0);
	SetRachet(1);
}

void Climber::Reset() {
	SetRachet(0);
}
