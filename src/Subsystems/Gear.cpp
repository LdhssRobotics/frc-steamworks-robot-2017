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

bool Gear::InCorrectPosition() {
	return gearEncoder->GetDistance() > 0.008;
}

void Gear::Reset() {

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
