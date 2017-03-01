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

void Climber::StartClimb() {
	rachetServo->Set(0);
	winchMotor->Set(1);
}

void Climber::StopClimb() {
	winchMotor->Set(0);
	rachetServo->Set(1);
}

void Climber::Reset() {

}
