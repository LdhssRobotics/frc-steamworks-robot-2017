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
	ballIntakeServo = RobotMap::ballIntakeServo;
}

void BallIntake::InitDefaultCommand() {

}
