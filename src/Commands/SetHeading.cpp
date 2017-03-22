#include "SetHeading.h"
#include "../Robot.h"
#include "WPILib.h"

// Set value for dampener
const float kP = 0.025;

SetHeading::SetHeading(float heading) :
		desHeading(heading)
{
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void SetHeading::Initialize()
{
	Robot::drivetrain->Reset();
	SetTimeout(3);
}

// Called repeatedly when this Command is scheduled to run
void SetHeading::Execute()
{
	//Determine amount to turn
	double turningValue = (desHeading - Robot::drivetrain->GetHeading())*kP;
	if (turningValue < -0.5) {
		turningValue = -0.5;
	} else if (turningValue > 0.5) {
		turningValue = 0.5;
	}
	//Turn robot
	Robot::drivetrain->frontLeftDrive->Set(turningValue);
	Robot::drivetrain->backLeftDrive->Set(turningValue);
	Robot::drivetrain->frontRightDrive->Set(turningValue);
	Robot::drivetrain->backRightDrive->Set(turningValue);

	//Display current heading on Smart Dashboard
	Robot::drivetrain->Log();
}

// Make this return true when this Command no longer needs to run execute()
bool SetHeading::IsFinished()
{
	//Determine if robot has attained target within 2 degrees on each side
	return IsTimedOut() || ((desHeading + 2) >= Robot::drivetrain->GetHeading() && ((desHeading - 2) <= Robot::drivetrain->GetHeading()));
}
// Called once after isFinished returns true
void SetHeading::End()
{
	Robot::drivetrain->Stop();
}

void SetHeading::Interrupted()
{
	End();
}
