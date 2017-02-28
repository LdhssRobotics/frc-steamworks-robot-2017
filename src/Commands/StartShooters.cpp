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
	SmartDashboard::PutString("Shooters:", "On");
	Robot::shooter->StartFlyWheelMotors();
	SetTimeout(3);
}

// Called repeatedly when this Command is scheduled to run
void StartShooters::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StartShooters::IsFinished()
{
	bool timedOut = IsTimedOut();
	if(timedOut) {
		SmartDashboard::PutString("Flywheels", "Ready");
	}
	else{
		SmartDashboard::PutString("Flywheels", "Not Ready");
	}
	return IsTimedOut();
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
