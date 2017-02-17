/*
 * RobotMap.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: programmer
 */

#include "RobotMap.h"
#include "Robot.h"
#include "LiveWindow/LiveWindow.h"
#include "Encoder.h"

// Ball intake subsystem
std::shared_ptr<SpeedController> RobotMap::ballIntakeMotor;

// Climber subsystem
std::shared_ptr<SpeedController> RobotMap::winchMotor;
std::shared_ptr<Servo> RobotMap::rachetServo;

// Drivetrain subsystem
std::shared_ptr<SpeedController> RobotMap::leftDrive;
std::shared_ptr<SpeedController> RobotMap::rightDrive;
std::shared_ptr<RobotDrive> RobotMap::robotDrive;

// Gear subsystem
std::shared_ptr<Encoder> RobotMap::gearEncoder;
std::shared_ptr<SpeedController> RobotMap::gearMotor;
std::shared_ptr<DigitalInput> RobotMap::gearLimitSwitch;

// Shooter subsystem
std::shared_ptr<SpeedController> RobotMap::flywheelMotor;
std::shared_ptr<DigitalInput> RobotMap::shooterLeftLimitSwitch;
std::shared_ptr<DigitalInput> RobotMap::shooterRightLimitSwitch;
std::shared_ptr<SpeedController> RobotMap::shooterHorizontalAdjust;
std::shared_ptr<Servo> RobotMap::shooterVerticalAdjust;
std::shared_ptr<Servo> RobotMap::ballStopper;
std::shared_ptr<Encoder> RobotMap::flywheelEncoder;

void RobotMap::init() {
	LiveWindow *lw = LiveWindow::GetInstance();

	// Ball intake subsystem
	ballIntakeMotor.reset(new Victor(0));

	// Climber subsystem
	winchMotor.reset(new Victor(2));
	rachetServo.reset(new Servo(3));

	// Drivetrain subsystem
	leftDrive.reset(new Victor(4));
	rightDrive.reset(new Victor(5));
	robotDrive.reset(new RobotDrive(leftDrive, rightDrive));

	robotDrive->SetSafetyEnabled(false);
	robotDrive->SetExpiration(0.1);
	robotDrive->SetSensitivity(0.65);
	robotDrive->SetMaxOutput(1.0);

	// Gear subsystem
	gearMotor.reset(new Victor(8));
	gearLimitSwitch.reset(new DigitalInput(1));
	lw->AddSensor("Gear", "Limit Switch", gearLimitSwitch);

	gearEncoder.reset(new Encoder(3, 4, false, Encoder::EncodingType::k4X));
	lw->AddSensor("Gear", "Encoder", gearEncoder);

	gearEncoder->SetMaxPeriod(0.1);
	gearEncoder->SetMinRate(1);
	gearEncoder->SetSamplesToAverage(7);
	gearEncoder->SetReverseDirection(false);
	gearEncoder->SetDistancePerPulse(1); // Not accurate measurement, ratio instead

	// Shooter subsystem
	flywheelMotor.reset(new Victor(8));

	shooterLeftLimitSwitch.reset(new DigitalInput(1));
	lw->AddSensor("Shooter", "Left Limit Switch", shooterLeftLimitSwitch);

	shooterRightLimitSwitch.reset(new DigitalInput(2));
	lw->AddSensor("Shooter", "Limit Switch 2", shooterRightLimitSwitch);

	shooterVerticalAdjust.reset(new Servo(9));
	lw->AddActuator("Shooter", "Vertical Angle Adjust", shooterVerticalAdjust);

	shooterHorizontalAdjust.reset(new Victor(7));

	ballStopper.reset(new Servo(10));
	lw->AddActuator("Shooter", "Ball Stopper", ballStopper);

	flywheelEncoder.reset(new Encoder(2, 3, false, Encoder::EncodingType::k4X));
	lw->AddSensor("Shooter", "Flywheel Encoder", flywheelEncoder);
}

void RobotMap::reset() {
	Robot::ballIntake->Reset();
	Robot::climber->Reset();
	Robot::drivetrain->Reset();
	Robot::gear->Reset();
	Robot::shooter->Reset();
}
