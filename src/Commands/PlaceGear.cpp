#include "PlaceGear.h"


PlaceGear::PlaceGear() {
	Requires(Robot::gear.get());

}

// Called just before this Command runs the first time
void PlaceGear::Initialize() {
	SmartDashboard::PutString("Gear:", "placing gear");
	Robot::gear->SetMotorSpeed(0.2); //flap moves forwards
}

void PlaceGear::Execute() {
	SmartDashboard::PutNumber("Gear encoder distance:", Robot::gear->GetPosition());
}
// Make this return true when this Command no longer needs to run execute()
bool PlaceGear::IsFinished() {
	return Robot::gear->InCorrectPosition();
}

// Called once after isFinished returns true
void PlaceGear::End() {
	Robot::gear->SetMotorSpeed(0);
	Wait(1.0); // Give time for the gear to fall and the pilot to pull it up
	SmartDashboard::PutString("Gear:", "done placing, waiting now");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PlaceGear::Interrupted() {
	End();
}
