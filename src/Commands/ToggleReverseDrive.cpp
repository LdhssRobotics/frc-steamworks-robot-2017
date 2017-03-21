#include "ToggleReverseDrive.h"

ToggleReverseDrive::ToggleReverseDrive() {
	Requires(Robot::drivetrain.get());
	Requires(Robot::vision.get());
}

// Called just before this Command runs the first time
void ToggleReverseDrive::Initialize() {
	Robot::drivetrain->isDriveReversed = false;
	Robot::vision->gearIsFront = true;

	SmartDashboard::PutString("What is the front?", "gear");
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleReverseDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ToggleReverseDrive::End() {
	Robot::drivetrain->isDriveReversed = true;
	Robot::vision->gearIsFront = false;

	SmartDashboard::PutString("What is the front?", "climber");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleReverseDrive::Interrupted() {
	End();
}
