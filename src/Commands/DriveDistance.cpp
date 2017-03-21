#include "DriveDistance.h"
#include "../Robot.h"

DriveDistance::DriveDistance(float distance):
	targetDistance(distance) {
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveDistance::Initialize() {
	Robot::drivetrain->Reset();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {
	Robot::drivetrain->ArcadeDrive(0.65, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished() {
	return (Robot::drivetrain->GetDistance() >= targetDistance);
}

// Called once after isFinished returns true
void DriveDistance::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted() {
	End();
}
