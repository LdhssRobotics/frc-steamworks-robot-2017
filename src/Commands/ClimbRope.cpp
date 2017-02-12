#include "ClimbRope.h"
#include "../Robot.h"
#include "../RobotMap.h"
#include "OI.h"

ClimbRope::ClimbRope() {
	Requires(Robot::climber.get());
}

// Called just before this Command runs the first time
void ClimbRope::Initialize() {
	SmartDashboard::PutString("Climber:", "climbing");
	Robot::climber->StartClimb();
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbRope::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClimbRope::End() {
	Robot::climber->StopClimb();
	SmartDashboard::PutString("Climber:", "not climbing");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbRope::Interrupted() {
	End();
}
