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
	Robot::gear->SetMotorSpeed(-0.4); // Tray moves inwards
	SetTimeout(1);
}

void GoBackGear::Execute() {
	Robot::gear->Log();
}

// Make this return true when this Command no longer needs to run execute()
bool GoBackGear::IsFinished() {
	// The timeout is to prevent damage should the limit switch not be hit
	// Loading a new gear will push the tray down to the return position
	return IsTimedOut() || Robot::gear->InCorrectReturnPosition();
}

// Called once after isFinished returns true
void GoBackGear::End() {
	Robot::gear->SetMotorSpeed(0);
	SmartDashboard::PutString("Gear:", "finished");
	Robot::gear->ResetEncoder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoBackGear::Interrupted() {
	End();
}
