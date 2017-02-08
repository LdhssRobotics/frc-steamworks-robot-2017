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
	ratchetServo = RobotMap::ratchetServo;
}

void Climber::InitDefaultCommand() {

}
