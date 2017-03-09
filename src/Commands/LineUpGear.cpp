#include "LineUpGear.h"

LineUpGear::LineUpGear() {
	Requires(Robot::drivetrain.get());
	Requires(Robot::vision.get());
	Requires(Robot::ultrasonicSubsystem.get());
}

// Called just before this Command runs the first time
void LineUpGear::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LineUpGear::Execute() {
	float speed;
	float turn;

	float distanceInches = Robot::ultrasonicSubsystem->GetRangeInches();

	if (distanceInches < 12) {
		speed = -0.5;
		turn = 0;
	}

	if ((distanceInches > 12) && (distanceInches < 30)) {
		speed = 0.2;

		if (Robot::vision->findTarget() == -1) {
			turn = -0.2;
		} else if (Robot::vision->findTarget() == 1) {
			turn = 0.2;
		} else {
			turn = 0;
		}
	} else if (distanceInches > 30) {
		speed = 0.4;

		if (Robot::vision->findTarget() == -1) {
			turn = -0.2;
		} else if (Robot::vision->findTarget() == 1) {
			turn = 0.2;
		} else {
			turn = 0;
		}
	} else {
		speed = -0.5;
		turn = 0;
	}

	Robot::drivetrain->ArcadeDrive(speed, turn);
}

// Make this return true when this Command no longer needs to run execute()
bool LineUpGear::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LineUpGear::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LineUpGear::Interrupted() {

}
