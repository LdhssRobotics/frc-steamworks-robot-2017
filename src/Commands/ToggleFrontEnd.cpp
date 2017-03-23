#include <Commands/ToggleFrontEnd.h>

ToggleFrontEnd::ToggleFrontEnd() {
}

// Called just before this Command runs the first time
void ToggleFrontEnd::Initialize() {
	Robot::drivetrain->isGearFront = false;
	SmartDashboard::PutString("Front of robot:", "climber");
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleFrontEnd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ToggleFrontEnd::End() {
	Robot::drivetrain->isGearFront = true;
	SmartDashboard::PutString("Front of robot:", "gear");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleFrontEnd::Interrupted() {
	End();
}
