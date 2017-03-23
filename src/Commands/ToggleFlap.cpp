#include "ToggleFlap.h"

ToggleFlap::ToggleFlap() {
	Requires(Robot::climber.get());
}

// Called just before this Command runs the first time
void ToggleFlap::Initialize() {
	Robot::climber->SetFlapPosition(1);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleFlap::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ToggleFlap::End() {
	Robot::climber->SetFlapPosition(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleFlap::Interrupted() {
	End();
}
