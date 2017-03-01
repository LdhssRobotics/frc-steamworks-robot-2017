#include "AimShooter.h"


AimShooter::AimShooter()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void AimShooter::Initialize()
{
	Robot::shooter->SetFlapAngle(1); // TODO: placeholder value
}

// Called repeatedly when this Command is scheduled to run
void AimShooter::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AimShooter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AimShooter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimShooter::Interrupted()
{

}
