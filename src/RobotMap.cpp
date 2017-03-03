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
	// PWM Ports
		// Ball intake subsystem
#define BALL_INTAKE_MOTOR_PORT 0

		// Climber subsystem
#define WINCH_MOTOR_PORT 1
#define RATCHET_SERVO_PORT 2

		// Drivetrain subsystem
#define LEFT_DRIVE_PORT 3
#define RIGHT_DRIVE_PORT 4

		// Gear subsystem
#define GEAR_MOTOR_PORT 5

		// Shooter subsystem
#define FLYWHEEL_MOTOR_1_PORT 6
#define FLYWHEEL_MOTOR_2_PORT 7
#define SHOOTER_FLAP_PORT 8
#define BALL_STOPPER_PORT 9
#define SHOOTER_HORIZONTAL_MOTOR_PORT 8

	// Digital Ports
		// Drivetrain subsystem
#define ULTRASONIC_ECHO_PORT 0
#define ULTRASONIC_TRIGGER_PORT 1

#define DRIVE_ENCODER_A_PORT 2
#define DRIVE_ENCODER_B_PORT 3

// Room for second drivetrain encoder to be added later
//#define DRIVE_ENCODER_2A_PORT 4
//#define DRIVE_ENCODER_2B_PORT 5

		// Gear subsystem
#define GEAR_ENCODER_A_PORT 6
#define GEAR_ENCODER_B_PORT 7

#define GEAR_LIMIT_SWITCH_PORT 8

		// Shooter subsystem
#define SHOOTER_LEFT_LIMIT_SWITCH_PORT 9

#define SHOOTER_RIGHT_LIMIT_SWITCH_PORT 10

#define FLYWHEEL_ENCODER_1A_PORT 11
#define FLYWHEEL_ENCODER_1B_PORT 12

#define FLYWHEEL_ENCODER_2A_PORT 13
#define FLYWHEEL_ENCODER_2B_PORT 14

		// Ultrasonic subsystem
#define ULTRASONIC_ECHO_PORT 0
#define ULTRASONIC_TRIGGER_PORT 1

#define ULTRASONIC_BACK_ECHO_PORT 15
#define ULTRASONIC_BACK_TRIGGER_PORT 16

	//Analog Ports
#define GYRO_PORT 0

// POINTERS

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
	ultrasonic.reset(new Ultrasonic(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_ECHO_PORT));
	lw->AddSensor("Drive", "Ultrasonic", ultrasonic);

	ultrasonic->SetAutomaticMode(true);

	driveEncoder.reset(new Encoder(DRIVE_ENCODER_A_PORT, DRIVE_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
	lw->AddSensor("Drive", "Encoder", driveEncoder);

	leftDrive.reset(new Victor(LEFT_DRIVE_PORT));
	rightDrive.reset(new Victor(RIGHT_DRIVE_PORT));
	rightDrive->SetInverted(true);
	robotDrive.reset(new RobotDrive(leftDrive, rightDrive));

	robotDrive->SetSafetyEnabled(false);
	robotDrive->SetExpiration(0.1);
	robotDrive->SetSensitivity(0.65);
	robotDrive->SetMaxOutput(1.0);

	gyro.reset(new AnalogGyro(GYRO_PORT));
	lw->AddSensor("Drive", "Gyro", gyro);
	gyro->SetSensitivity(0.00666);
	gyro->Calibrate();

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

//	shooterFlap.reset(new Servo(SHOOTER_FLAP_PORT));
//	lw->AddActuator("Shooter", "Vertical Angle Adjust", shooterFlap);

	shooterHorizontalMotor.reset(new Victor(SHOOTER_HORIZONTAL_MOTOR_PORT));
	//shooterHorizontalMotor.reset(new Victor(16));

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
	Robot::ultrasonicSubsystem->Reset();
}
