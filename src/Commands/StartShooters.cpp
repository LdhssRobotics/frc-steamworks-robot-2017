#include "StartShooters.h"

StartShooters::StartShooters()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void StartShooters::Initialize()
{
	SmartDashboard::PutString("Flywheels:", "speeding up...");
	Robot::shooter->StartFlyWheelMotors();
	SetTimeout(3);
}

// Make this return true when this Command no longer needs to run execute()
bool StartShooters::IsFinished()
{
	bool timedOut = IsTimedOut();
	if(timedOut) {
		SmartDashboard::PutString("Flywheels:", "ready");
	}
	return timedOut;
}

// Called once after isFinished returns true
void StartShooters::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StartShooters::Interrupted()
{

}
