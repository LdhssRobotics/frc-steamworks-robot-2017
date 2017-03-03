#include "CollectGear.h"

CollectGear::CollectGear() {
	Requires(Robot::gear.get());
}

// Called just before this Command runs the first time
void CollectGear::Initialize() {
	SmartDashboard::PutString("Gear:", "collecting gear");
	Robot::gear->SetMotorSpeed(0.4);
}

// Called repeatedly when this Command is scheduled to run
void CollectGear::Execute() {
	Robot::gear->Log();
}

// Make this return true when this Command no longer needs to run execute()
bool CollectGear::IsFinished() {
	return Robot::gear->InCorrectCollectPosition();
}

// Called once after isFinished returns true
void CollectGear::End() {
	Robot::gear->SetMotorSpeed(0);
	SmartDashboard::PutString("Gear:", "waiting");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CollectGear::Interrupted() {
	SmartDashboard::PutString("Gear:", "Interrupted");
	End();
}
