#include "StopShooters.h"

StopShooters::StopShooters()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void StopShooters::Initialize()
{
	SmartDashboard::PutString("Shooters:", "Off");
	Robot::shooter->StopFlyWheelMotors();
	SetTimeout(3);
}

// Called repeatedly when this Command is scheduled to run
void StopShooters::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopShooters::IsFinished()
{
	bool timedOut = IsTimedOut();
		if(timedOut) {
			SmartDashboard::PutString("Shooters", "Stopped");
		}
		else{
			SmartDashboard::PutString("Shooters", "Not Stopped Yet");
		}
		return IsTimedOut();
}

// Called once after isFinished returns true
void StopShooters::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopShooters::Interrupted()
{

}
