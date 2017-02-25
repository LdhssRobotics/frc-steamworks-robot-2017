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

// PORT MAPPINGS
#define BALL_INTAKE_MOTOR_PORT 0 //PWM
#define WINCH_MOTOR_PORT 1 //PWM
#define RATCHET_SERVO_PORT 2 //PWM
#define GYRO_PORT 0 //Analog
#define ULTRASONIC_ECHO_PORT 0 //Digital
#define ULTRASONIC_TRIGGER_PORT 1 //Digital
#define DRIVE_ENCODER_A_PORT 2 //Digital
#define DRIVE_ENCODER_B_PORT 3 //Digital
#define LEFT_DRIVE_PORT 3 //PWM
#define RIGHT_DRIVE_PORT 4 //PWM
#define GEAR_ENCODER_A_PORT 4 //Digital
#define GEAR_ENCODER_B_PORT 5 //Digital
#define GEAR_MOTOR_PORT 5 //PWM
#define GEAR_LIMIT_SWITCH_PORT 6 //Digital
#define FLYWHEEL_MOTOR_1_PORT 6 //PWM
#define FLYWHEEL_MOTOR_2_PORT 7 //PWM
#define SHOOTER_LEFT_LIMIT_SWITCH_PORT 7 //Digital
#define SHOOTER_RIGHT_LIMIT_SWITCH_PORT 8 //Digital
#define SHOOTER_FLAP_PORT 8 //PWM
#define BALL_STOPPER_PORT 9 //PWM
#define SHOOTER_HORIZONTAL_MOTOR_PORT 10 //PWM
#define FLYWHEEL_ENCODER_1A_PORT 9 //Digital
#define FLYWHEEL_ENCODER_1B_PORT 10 //Digital
#define FLYWHEEL_ENCODER_2A_PORT 11 //Digital
#define FLYWHEEL_ENCODER_2B_PORT 12 //Digital

// Ball intake subsystem
std::shared_ptr<SpeedController> RobotMap::ballIntakeMotor;

// Climber subsystem
std::shared_ptr<SpeedController> RobotMap::winchMotor;
std::shared_ptr<Servo> RobotMap::rachetServo;

// Drivetrain subsystem
std::shared_ptr<AnalogGyro> RobotMap::gyro;
std::shared_ptr<Ultrasonic> RobotMap::ultrasonic;
std::shared_ptr<Encoder> RobotMap::driveEncoder;
std::shared_ptr<SpeedController> RobotMap::leftDrive;
std::shared_ptr<SpeedController> RobotMap::rightDrive;
std::shared_ptr<RobotDrive> RobotMap::robotDrive;

// Gear subsystem
std::shared_ptr<Encoder> RobotMap::gearEncoder;
std::shared_ptr<SpeedController> RobotMap::gearMotor;
std::shared_ptr<DigitalInput> RobotMap::gearLimitSwitch;

// Shooter subsystem
std::shared_ptr<SpeedController> RobotMap::flywheelMotor1;
std::shared_ptr<SpeedController> RobotMap::flywheelMotor2;
std::shared_ptr<DigitalInput> RobotMap::shooterLeftLimitSwitch;
std::shared_ptr<DigitalInput> RobotMap::shooterRightLimitSwitch;
std::shared_ptr<SpeedController> RobotMap::shooterHorizontalMotor;
std::shared_ptr<Servo> RobotMap::shooterFlap;
std::shared_ptr<Servo> RobotMap::ballStopper;
std::shared_ptr<Encoder> RobotMap::flywheelEncoder1;
std::shared_ptr<Encoder> RobotMap::flywheelEncoder2;

void RobotMap::init() {
	LiveWindow *lw = LiveWindow::GetInstance();

	// Ball intake subsystem
	ballIntakeMotor.reset(new Victor(BALL_INTAKE_MOTOR_PORT));

	// Climber subsystem
	winchMotor.reset(new Victor(WINCH_MOTOR_PORT));
	rachetServo.reset(new Servo(RATCHET_SERVO_PORT));

	// Drivetrain subsystem
	gyro.reset(new AnalogGyro(GYRO_PORT));
	lw->AddSensor("Drive", "Gyro", gyro);

	ultrasonic.reset(new Ultrasonic(ULTRASONIC_ECHO_PORT, ULTRASONIC_TRIGGER_PORT));
	lw->AddSensor("Drive", "Ultraonic", ultrasonic);

	driveEncoder.reset(new Encoder(DRIVE_ENCODER_A_PORT, DRIVE_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
	lw->AddSensor("Drive", "Encoder", driveEncoder);

	leftDrive.reset(new Victor(LEFT_DRIVE_PORT));
	rightDrive.reset(new Victor(RIGHT_DRIVE_PORT));
	robotDrive.reset(new RobotDrive(leftDrive, rightDrive));

	robotDrive->SetSafetyEnabled(false);
	robotDrive->SetExpiration(0.1);
	robotDrive->SetSensitivity(0.65);
	robotDrive->SetMaxOutput(1.0);

	// Gear subsystem
	gearMotor.reset(new Victor(GEAR_MOTOR_PORT));
	gearLimitSwitch.reset(new DigitalInput(GEAR_LIMIT_SWITCH_PORT));
	lw->AddSensor("Gear", "Limit Switch", gearLimitSwitch);

	gearEncoder.reset(new Encoder(GEAR_ENCODER_A_PORT,
			GEAR_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
	lw->AddSensor("Gear", "Encoder", gearEncoder);

	gearEncoder->SetMaxPeriod(0.1);
	gearEncoder->SetMinRate(1);
	gearEncoder->SetSamplesToAverage(7);
	gearEncoder->SetReverseDirection(false);
	gearEncoder->SetDistancePerPulse(1); // Not accurate measurement, ratio instead

	// Shooter subsystem
	flywheelMotor1.reset(new Victor(FLYWHEEL_MOTOR_1_PORT));
	flywheelMotor2.reset(new Victor(FLYWHEEL_MOTOR_2_PORT));

	shooterLeftLimitSwitch.reset(new DigitalInput(SHOOTER_LEFT_LIMIT_SWITCH_PORT));
	lw->AddSensor("Shooter", "Left Limit Switch", shooterLeftLimitSwitch);

	shooterRightLimitSwitch.reset(new DigitalInput(SHOOTER_RIGHT_LIMIT_SWITCH_PORT));
	lw->AddSensor("Shooter", "Limit Switch 2", shooterRightLimitSwitch);

	shooterFlap.reset(new Servo(SHOOTER_FLAP_PORT));
	lw->AddActuator("Shooter", "Vertical Angle Adjust", shooterFlap);

	shooterHorizontalMotor.reset(new Victor(SHOOTER_HORIZONTAL_MOTOR_PORT));

	ballStopper.reset(new Servo(BALL_STOPPER_PORT));
	lw->AddActuator("Shooter", "Ball Stopper", ballStopper);

	flywheelEncoder1.reset(new Encoder(FLYWHEEL_ENCODER_1A_PORT,
			FLYWHEEL_ENCODER_1B_PORT, false, Encoder::EncodingType::k4X));
	lw->AddSensor("Shooter", "Flywheel Encoder", flywheelEncoder1);

	flywheelEncoder2.reset(new Encoder(FLYWHEEL_ENCODER_2A_PORT,
			FLYWHEEL_ENCODER_2B_PORT, false, Encoder::EncodingType::k4X));
}

void RobotMap::reset() {
	Robot::ballIntake->Reset();
	Robot::climber->Reset();
	Robot::drivetrain->Reset();
	Robot::gear->Reset();
	Robot::shooter->Reset();
}
