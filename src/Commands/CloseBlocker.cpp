#include "CloseBlocker.h"

CloseBlocker::CloseBlocker()
{
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void CloseBlocker::Initialize()
{
	Robot::shooter->CloseBlocker();
	SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void CloseBlocker::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CloseBlocker::IsFinished()
{
	bool timedOut = IsTimedOut();
		if(timedOut) {
			SmartDashboard::PutString("Blocker", "Closed");
		}
		else{
			SmartDashboard::PutString("Blocker", "Not Closed");
		}
		return IsTimedOut();
}

// Called once after isFinished returns true
void CloseBlocker::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseBlocker::Interrupted()
{

}
