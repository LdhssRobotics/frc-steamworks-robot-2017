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
	flapServo = RobotMap::flapServo;
}

void Climber::StartClimb() {
	rachetServo->Set(0);
	winchMotor->Set(1);
}

void Climber::StopClimb() {
	winchMotor->Set(0);
	rachetServo->Set(1);
}

void Climber::ReverseClimb() {
	winchMotor->Set(-1);
	rachetServo->Set(0);
}

void Climber::SlowClimb(){
	winchMotor->Set(0.5);
}

void Climber::SetFlapPosition(float position) {
	flapServo->Set(position);
}

void Climber::Reset() {
	rachetServo->Set(0);
	winchMotor->Set(0);
	flapServo->Set(0.22);
}
