#include "Subsystems/Gear.h"
#include "../Robot.h"
#include "../RobotMap.h"

Gear::Gear() : Subsystem("Gear") {
	gearEncoder = RobotMap::gearEncoder;
	gearMotor = RobotMap::gearMotor;
	gearLimitSwitch = RobotMap::gearLimitSwitch;
}

void Gear::SetMotorSpeed(float speed) { //GO FORWARD
	gearMotor->Set(speed);
}

/*void Gear::GoBackMotorSpeed(float speed){
		gearMotor->Set(-speed);
	}
	*/
float Gear::GetPosition() {
	return gearEncoder->GetDistance();
}

bool Gear::InCorrectReturnPosition(){
		float y;
		y = gearEncoder->GetDistance();
		SmartDashboard::PutNumber("Go Back", y);
		return  y > 0; // A quarter turn backwards
	}

bool Gear::InCorrectPosition() {
	float x;
	x = gearEncoder->GetDistance();
	SmartDashboard::PutNumber("IsFinished", x);
	return  x < -120; // A quarter turn
	}

void Gear::ResetEncoder(){
	gearEncoder->Reset();
}

void Gear::Reset() {
	ResetEncoder();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
