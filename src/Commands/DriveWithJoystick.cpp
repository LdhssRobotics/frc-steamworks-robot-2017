#include "DriveWithJoystick.h"
#include "Subsystems/Drivetrain.h"
#include "../Robot.h"
#include "../OI.h"

DriveWithJoystick::DriveWithJoystick() {
	Requires(Robot::drivetrain.get());
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	float speed = Robot::oi->joystick1->GetRawAxis(OI::LEFT_Y_AXIS);
	float turn = -(Robot::oi->joystick1->GetRawAxis(OI::LEFT_X_AXIS));
	Robot::drivetrain->ArcadeDrive(speed, turn);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {
	End();
}
