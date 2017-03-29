#include "DriveDistance.h"
#include "../Robot.h"

// Set value for dampener
const float kP = 0.025;

DriveDistance::DriveDistance(float distance):
	targetDistance(distance)
{
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveDistance::Initialize() {
	Robot::drivetrain->Reset();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {
	SmartDashboard::PutNumber("Distance travelled", Robot::drivetrain->GetDistance());
	SmartDashboard::PutNumber("Target Distance", targetDistance);
	Robot::drivetrain->ArcadeDrive(-0.65, 0.05);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished() {
	return (abs(Robot::drivetrain->GetDistance()) >= targetDistance);
}

// Called once after isFinished returns true
void DriveDistance::End() {
	Robot::drivetrain->Stop();
	// Ensure the robot has stopped moving before another command is used
	Wait(1);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted() {
	End();
}
