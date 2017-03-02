#include "DriveDistance.h"
#include "../Robot.h"

DriveDistance::DriveDistance(float speed, float time):mspeed(speed), duration(time) {


	Requires(Robot::drivetrain.get());

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveDistance::Initialize() {
	SetTimeout(duration);
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {
	Robot::drivetrain->ArcadeDrive(mspeed, 0);

}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished() {
	return IsTimedOut();
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
