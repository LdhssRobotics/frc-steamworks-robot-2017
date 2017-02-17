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
		float y;
		y = gearEncoder->GetDistance();
		SmartDashboard::PutNumber("Go Back", y);
		return  y > 0; // A quarter turn backwards (stop when angle is more than 0)
	}

//Check when it is at the desired position (120 degrees from origin ccw)
bool Gear::InCorrectPosition() {
	float x;
	x = gearEncoder->GetDistance();
	SmartDashboard::PutNumber("IsFinished", x);
	return  x < -100; // A quarter turn
	}

void Gear::ResetEncoder(){
	gearEncoder->Reset();
}

void Gear::Reset() {
	ResetEncoder();
}

