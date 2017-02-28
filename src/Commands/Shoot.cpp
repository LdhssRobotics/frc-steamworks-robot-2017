#include "Shoot.h"
#include "../Robot.h"
#include "../RobotMap.h"
#include "OI.h"
Shoot::Shoot() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::shooter.get());
}

//Starting the shooters
void Shoot::ShooterOn() {
	SmartDashboard::PutString("Shooters:", "On");
	Robot::shooter->StartFlyWheelMotors();
	Robot::shooter->OpenBlocker();
}

//Stopping the Shooter
void Shoot::ShooterOff() {
	Robot::shooter->StopFlyWheelMotors();
	Robot::shooter->CloseBlocker();
	SmartDashboard::PutString("Shooters:", "Off");
}

// Stopping the program
bool Shoot::IsFinished() {
	return false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	End();
}
