#include "ToggleReverseDrive.h"

ToggleReverseDrive::ToggleReverseDrive() {
}

// Called just before this Command runs the first time
void ToggleReverseDrive::Initialize() {
	Robot::drivetrain->isDriveReversed = true;

	SmartDashboard::PutString("Front of robot:", "Climber");
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleReverseDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ToggleReverseDrive::End() {
	Robot::drivetrain->isDriveReversed = false;

	SmartDashboard::PutString("Front of robot:", "Gear");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleReverseDrive::Interrupted() {
	End();
}
