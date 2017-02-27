#include "Shooter.h"
#include "../RobotMap.h"
#include "../Robot.h"

Shooter::Shooter() : Subsystem("Shooter") {
	flywheelMotor1 = RobotMap::flywheelMotor1;
	flywheelMotor2 = RobotMap::flywheelMotor2;
	shooterLeftLimitSwitch = RobotMap::shooterLeftLimitSwitch;
	shooterRightLimitSwitch = RobotMap::shooterRightLimitSwitch;
	shooterHorizontalMotor = RobotMap::shooterHorizontalMotor;
	shooterFlap = RobotMap::shooterFlap;
	ballStopper = RobotMap::ballStopper;
	flywheelEncoder1 = RobotMap::flywheelEncoder1;
	flywheelEncoder2 = RobotMap::flywheelEncoder2;
}

void Shooter::Reset() {

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
