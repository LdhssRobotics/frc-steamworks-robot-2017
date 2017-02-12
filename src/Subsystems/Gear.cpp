#include "Subsystems/Gear.h"
#include "../Robot.h"
#include "../RobotMap.h"

Gear::Gear() : Subsystem("Gear") {
	gearEncoder = RobotMap::gearEncoder;
	gearServo = RobotMap::gearServo;
}

void Gear::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Gear::Reset() {

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
