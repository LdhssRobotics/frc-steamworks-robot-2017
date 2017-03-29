/*
 * Climber.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: programmer
 */

#include "Climber.h"
#include "../Robot.h"
#include "../RobotMap.h"

Climber::Climber() : Subsystem("Climber") {
	winchMotor = RobotMap::winchMotor;
	rachetServo = RobotMap::rachetServo;
}

void Climber::StartClimb() {
	rachetServo->Set(0);
	Wait(0.5); // Allow the servo to unlock before starting winch
	winchMotor->Set(1);
}

void Climber::StopClimb() {
	rachetServo->Set(1);
	Wait(0.5); // Allow the servo to lock before stopping winch
	winchMotor->Set(0);
}

void Climber::ReverseClimb() {
	rachetServo->Set(0);
	Wait(0.5); // Allow the servo to unlock before starting winch
	winchMotor->Set(-1);
}

void Climber::Reset() {

}
