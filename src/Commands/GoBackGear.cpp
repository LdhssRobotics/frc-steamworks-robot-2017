/*
 * GoBackGear.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: programmer
 */

#include <Commands/GoBackGear.h>


GoBackGear::GoBackGear() {
	Requires(Robot::gear.get());

}

// Called just before this Command runs the first time
void GoBackGear::Initialize() {
	SmartDashboard::PutString("Gear:", "going back");
	Robot::gear->SetMotorSpeed(-0.2); //GO BACKWARDS
}

// Make this return true when this Command no longer needs to run execute()
bool GoBackGear::IsFinished() {
	return Robot::gear->InCorrectReturnPosition();

}

// Called once after isFinished returns true
void GoBackGear::End() {
	Robot::gear->SetMotorSpeed(0);
	SmartDashboard::PutString("Gear:", "hello back");
	Robot::gear->ResetEncoder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoBackGear::Interrupted() {
	End();
}