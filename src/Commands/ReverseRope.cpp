#include "ReverseRope.h"
#include "../Robot.h"
#include "../RobotMap.h"
#include "OI.h"

ReverseRope::ReverseRope() {
	Requires(Robot::climber.get());
}

// Called just before this Command runs the first time
void ReverseRope::Initialize() {
	Robot::climber->ReverseClimb();
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseRope::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ReverseRope::End() {
	Robot::climber->StopClimb();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseRope::Interrupted() {
	End();
}
