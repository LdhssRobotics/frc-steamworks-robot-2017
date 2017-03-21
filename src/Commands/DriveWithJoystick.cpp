#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() {
	Requires(Robot::drivetrain.get());
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	float speedConstant = 1;
	float turnConstant = 1;
	if (Robot::drivetrain->isDriveReversed) {
		float speedConstant = -1;
		float turnConstant = -1;
	}

	float speed = speedConstant * -Robot::oi->driveStick->GetRawAxis(OI::LEFT_Y_AXIS);
	float turn = turnConstant * -0.75 * Robot::oi->driveStick->GetRawAxis(OI::RIGHT_X_AXIS);

	if (Robot::oi->driveStick->GetRawButton(5)) {
		speed = 0.65 * speed;
	}

	if (Robot::oi->driveStick->GetRawButton(6)) {
		turn = 0.8 * turn;
	}

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
