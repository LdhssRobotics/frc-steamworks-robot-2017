#include "Subsystems/Gear.h"
#include "../Robot.h"
#include "../RobotMap.h"

Gear::Gear() : Subsystem("Gear") {
	gearEncoder = RobotMap::gearEncoder;
	gearMotor = RobotMap::gearMotor;
	gearLimitSwitch = RobotMap::gearLimitSwitch;
}

void Gear::SetMotorSpeed(float speed) {
	gearMotor->Set(speed);
}

//checks the current position of the encoder
float Gear::GetPosition() {
	return gearEncoder->GetDistance();
}

//Check when it is reset to original position
bool Gear::InCorrectReturnPosition(){
	return !(gearLimitSwitch->Get());
	}

//Check when it is at the desired position (80 degrees from origin
bool Gear::InCorrectPosition() {
	return gearEncoder->GetDistance() > 135; // Roughly a quarter turn
	}

bool Gear::InCorrectCollectPosition() {
	return gearEncoder->GetDistance() > 90;
}

void Gear::ResetEncoder(){
	gearEncoder->Reset();
	Log();
}

void Gear::Reset() {
	ResetEncoder();
}

void Gear::Log() {
	SmartDashboard::PutNumber("Gear encoder:", GetPosition());
}

