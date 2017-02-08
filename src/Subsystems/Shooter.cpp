#include "Shooter.h"
#include "../RobotMap.h"
#include "../Robot.h"

Shooter::Shooter() : Subsystem("Shooter") {
	shooterHorizontalAdjust = RobotMap::shooterHorizontalAdjust;
	shooterFlywheelVictor = RobotMap::shooterFlywheelVictor;
	shooterLimitSwitch1 = RobotMap::shooterLimitSwitch1;
	shooterLimitSwitch2 = RobotMap::shooterLimitSwitch2;
	shooterVerticalAdjust = RobotMap::shooterVerticalAdjust;
	shooterBallStopper = RobotMap::shooterBallStopper;
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
