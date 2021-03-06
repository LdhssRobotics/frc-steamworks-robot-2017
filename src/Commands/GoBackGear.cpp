/*
 * GoBackGear.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: programmer
 */
#include "GoBackGear.h"

GoBackGear::GoBackGear() {
	Requires(Robot::gear.get());
}

// Called just before this Command runs the first time
void GoBackGear::Initialize() {
	SmartDashboard::PutString("Gear:", "returning");
	Robot::gear->SetMotorSpeed(-0.4); //GO BACKWARDS
	SetTimeout(1);
}

void GoBackGear::Execute() {
	Robot::gear->Log();
}

// Make this return true when this Command no longer needs to run execute()
bool GoBackGear::IsFinished() {
	return IsTimedOut() || Robot::gear->InCorrectReturnPosition();
}

// Called once after isFinished returns true
void GoBackGear::End() {
	Wait(0.01);
	Robot::gear->SetMotorSpeed(0);
	SmartDashboard::PutString("Gear:", "finished");
	Robot::gear->ResetEncoder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoBackGear::Interrupted() {
	End();
}
