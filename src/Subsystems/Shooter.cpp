#include "Shooter.h"
#include "../RobotMap.h"
#include "../Robot.h"

Shooter::Shooter() : Subsystem("Shooter") {
	flywheelMotor = RobotMap::flywheelMotor;
	shooterLeftLimitSwitch = RobotMap::shooterLeftLimitSwitch;
	shooterRightLimitSwitch = RobotMap::shooterRightLimitSwitch;
	shooterHorizontalAdjust = RobotMap::shooterHorizontalAdjust;
	shooterVerticalAdjust = RobotMap::shooterVerticalAdjust;
	ballStopper = RobotMap::ballStopper;
	flywheelEncoder = RobotMap::flywheelEncoder;
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Shooter::Reset() {

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
