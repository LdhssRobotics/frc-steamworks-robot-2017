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
	// Determine amount to turn
	double turningValue = (desHeading - Robot::drivetrain->GetHeading())*kP;
	if (turningValue < -0.25) {
		turningValue = -0.4;
	} else if (turningValue > 0.25) {
		turningValue = 0.4;
	}

	// Turn robot
	Robot::drivetrain->ArcadeDrive(0, turningValue);

	// Display current heading on SmartDashboard
	Robot::drivetrain->Log();
}

// Make this return true when this Command no longer needs to run execute()
bool SetHeading::IsFinished()
{
	// Determine if robot has attained target within 2 degrees on each side
	// Timeout is a failsafe
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
