/*
 * RobotMap.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: programmer
 */

#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// Ball intake subsystem
std::shared_ptr<SpeedController> RobotMap::ballIntakeMotor;
std::shared_ptr<Servo> RobotMap::ballIntakeServo;

// Climber subsystem
std::shared_ptr<SpeedController> RobotMap::winchMotor;
std::shared_ptr<Servo> RobotMap::ratchetServo;
std::shared_ptr<Encoder> RobotMap::climberEncoder;

// Drivetrain subsystem
std::shared_ptr<SpeedController> RobotMap::drivetrainSpeedController1;
std::shared_ptr<SpeedController> RobotMap::drivetrainSpeedController2;
std::shared_ptr<RobotDrive> RobotMap::robotDrive;

// Gear subsystem
std::shared_ptr<Encoder> RobotMap::gearEncoder;
std::shared_ptr<Servo> RobotMap::gearServo;

// Shooter subsystem
std::shared_ptr<SpeedController> RobotMap::shooterHorizontalAdjust;
std::shared_ptr<SpeedController> RobotMap::shooterFlywheelVictor;
std::shared_ptr<DigitalInput> RobotMap::shooterLimitSwitch1;
std::shared_ptr<DigitalInput> RobotMap::shooterLimitSwitch2;
std::shared_ptr<Servo> RobotMap::shooterVerticalAdjust;
std::shared_ptr<Servo> RobotMap::shooterBallStopper;

void RobotMap::init() {
	LiveWindow *lw = LiveWindow::GetInstance();

	// Ball intake subsystem
	ballIntakeMotor.reset(new Victor(0));
	ballIntakeServo.reset(new Servo(1));

	// Climber subsystem
	winchMotor.reset(new Victor(2));
	ratchetServo.reset(new Servo(3));
	climberEncoder.reset(new Encoder(0));

	// Drivetrain subsystem
	drivetrainSpeedController1.reset(new Victor(4));
	drivetrainSpeedController2.reset(new Victor(5));
	robotDrive.reset(new RobotDrive(drivetrainSpeedController1, drivetrainSpeedController2));

	robotDrive->SetSafetyEnabled(false);
	robotDrive->SetExpiration(0.1);
	robotDrive->SetSensitivity(0.65);
	robotDrive->SetMaxOutput(1.0);

	// Gear subsystem
	gearEncoder.reset(new Encoder(1));
	gearServo.reset(new Servo(6));

	// Shooter subsystem
	shooterHorizontalAdjust.reset(new Victor(7));
	shooterFlywheelVictor.reset(new Victor(8));
	shooterLimitSwitch1.reset(new DigitalInput(0));
	shooterLimitSwitch2.reset(new DigitalInput(1));
	shooterVerticalAdjust.reset(new Servo(9));
	shooterBallStopper.reset(new Servo(10));
}
