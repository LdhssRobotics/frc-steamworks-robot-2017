#include "GetUltrasonic.h"

GetUltrasonic::GetUltrasonic() {
	Requires(Robot::ultrasonicSubsystem.get());
}

// Called repeatedly when this Command is scheduled to run
void GetUltrasonic::Execute() {
	Robot::ultrasonicSubsystem->GetRange();
}

// Make this return true when this Command no longer needs to run execute()
bool GetUltrasonic::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GetUltrasonic::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetUltrasonic::Interrupted() {
	End();
}
