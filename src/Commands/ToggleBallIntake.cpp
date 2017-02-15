#include "ToggleBallIntake.h"
#include "../Robot.h"
#include "../OI.h"
#include "Subsystems/BallIntake.h"

const float ToggleBallIntake::INTAKE_SPEED = 1;
const float ToggleBallIntake::REVERSEINTAKE_SPEED = -1;

ToggleBallIntake::ToggleBallIntake(float speed):
		intakeSpeed(speed)
{
	Requires(Robot::ballIntake.get());
}

// Called just before this Command runs the first time

void ToggleBallIntake::Initialize(){
	Robot::ballIntake->SetIntakeSpeed(intakeSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleBallIntake::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ToggleBallIntake::End() {
	Robot::ballIntake->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleBallIntake::Interrupted() {
	End();
}
