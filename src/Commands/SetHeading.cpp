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
	Robot::drivetrain->leftDrive->Set(turningValue);
	Robot::drivetrain->rightDrive->Set(turningValue);

	//Display current heading on Smart Dashboard
	SmartDashboard::PutNumber("RobotHeadingInDegrees", Robot::drivetrain->GetHeading());
}

// Make this return true when this Command no longer needs to run execute()
bool SetHeading::IsFinished()
{
	//Determine if robot has attained target within 2 degrees on each side
	return ((desHeading+2) >= Robot::drivetrain->GetHeading() && ((desHeading-2) <= Robot::drivetrain->GetHeading()));
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
