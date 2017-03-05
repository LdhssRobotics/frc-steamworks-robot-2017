#include "CatchRope.h"

CatchRope::CatchRope() {
	Requires(Robot::climber.get());
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CatchRope::Initialize() {
	Robot::climber->SlowClimb();
}

// Called repeatedly when this Command is scheduled to run
void CatchRope::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool CatchRope::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CatchRope::End() {
	Robot::climber->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CatchRope::Interrupted() {
	End();
}
