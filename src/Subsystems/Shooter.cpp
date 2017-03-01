#include "Shooter.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include <math.h>

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

void Shooter::MoveHorizontalMotor(float horizontalMotorSpeed){
	if((shooterLeftLimitSwitch==false) && (shooterRightLimitSwitch==false)) {
		shooterHorizontalMotor->Set(horizontalMotorSpeed);
	}
	else {
		shooterHorizontalMotor->Set(0);
	}
}

void Shooter::StartFlyWheelMotors(){
	flywheelMotor1->Set(1);
	flywheelMotor2->Set(-1);
}

void Shooter::StopFlyWheelMotors(){
	flywheelMotor1->Set(0);
	flywheelMotor2->Set(0);
}

void Shooter::SetFlapAngle(float flapAngle)
{
   shooterFlap->Set(120.65*cos(flapAngle)/50); //value between 0 and 1 for flap servo
}

void Shooter::Reset(){
  CloseBlocker();
  StopFlyWheelMotors();
}

void Shooter::CloseBlocker(){
	ballStopper->Set(1);
}

void Shooter::OpenBlocker(){
	ballStopper->Set(0);
}

//Put methods for controlling this subsystem
// here. Call these from Commands.
