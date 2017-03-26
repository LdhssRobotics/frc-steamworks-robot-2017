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
	Wait(0.5);
	winchMotor->Set(1);
}

void Climber::StopClimb() {
	rachetServo->Set(1);
	Wait(0.5);
	winchMotor->Set(0);
}

void Climber::ReverseClimb() {
	rachetServo->Set(0);
	Wait(0.5);
	winchMotor->Set(-1);
}

void Climber::SlowClimb(){
	winchMotor->Set(0.5);
}

void Climber::SetFlapPosition(float position) {
	flapServo->Set(position);
}

void Climber::Reset() {
	rachetServo->Set(1);
	winchMotor->Set(0);
	flapServo->Set(0.22);
}
