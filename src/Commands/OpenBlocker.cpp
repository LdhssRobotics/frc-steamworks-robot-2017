#include "OpenBlocker.h"

OpenBlocker::OpenBlocker()
{
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void OpenBlocker::Initialize()
{
	Robot::shooter->OpenBlocker();
	SetTimeout(0.5);
}

// Called repeatedly when this Command is scheduled to run
void OpenBlocker::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool OpenBlocker::IsFinished()
{
	bool timedOut = IsTimedOut();
		if(timedOut) {
			SmartDashboard::PutString("Ball blocker", "not blocking");
		}
		return timedOut;
}

// Called once after isFinished returns true
void OpenBlocker::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenBlocker::Interrupted()
{

}
