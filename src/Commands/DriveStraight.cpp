#include "Commands/DriveStraight.h"
#include "../Robot.h"

DriveStraight::DriveStraight(float speed, float duration) :
	heading(0),
	speed(-speed),
	duration(duration)
{
	Requires(Robot::drivetrain.get());
}

void DriveStraight::Initialize()
{
	Robot::drivetrain->Reset();
	SetTimeout(duration);
	heading = Robot::drivetrain->GetHeading();
}

void DriveStraight::Execute()
{
    float currentHeading = Robot::drivetrain->GetHeading();
	Robot::drivetrain->ArcadeDrive(speed, (heading-currentHeading) * 0.08);
}

bool DriveStraight::IsFinished()
{
	return IsTimedOut();
}

void DriveStraight::End() { }

void DriveStraight::Interrupted()
{
	End();
}
