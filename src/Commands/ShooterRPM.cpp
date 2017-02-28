#include "ShooterRPM.h"

ShooterRPM::ShooterRPM() {
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void ShooterRPM::Initialize() {
	//Robot::shooter->moveMotor1();

}

// Called repeatedly when this Command is scheduled to run
void ShooterRPM::Execute() {
	Robot::shooter->moveMotor1();
	Robot::shooter->getRPMfromEncoder();
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterRPM::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShooterRPM::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterRPM::Interrupted() {

}
