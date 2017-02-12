#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() {
	Requires(Robot::drivetrain.get());
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	/* On driveStick, left y-axis controls forward/backwards movement,
	 * right x-axis controls turn */
	Robot::drivetrain->ArcadeDrive(Robot::oi->driveStick->GetRawAxis(OI::LEFT_Y_AXIS),
			-(Robot::oi->driveStick->GetRawAxis(OI::RIGHT_X_AXIS)));
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
