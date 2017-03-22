/*
2 * RobotMap.cpp
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
		// Climber subsystem
#define WINCH_MOTOR_PORT 4
#define RATCHET_SERVO_PORT 5
#define CLIMBER_ARM_PORT 6

		// Drivetrain subsystem
#define FRONT_LEFT_DRIVE_PORT 0
#define BACK_LEFT_DRIVE_PORT 1
#define FRONT_RIGHT_DRIVE_PORT 2
#define BACK_RIGHT_DRIVE_PORT 3

		// Gear subsystem
#define GEAR_MOTOR_PORT 9

		// Low ball shooter subsystem
#define LEFT_LOW_BALL_ARM_PORT 7
#define RIGHT_LOW_BALL_ARM_PORT 8

	// Digital Ports
		// Drivetrain subsystem
#define DRIVE_ENCODER_A_PORT 0
#define DRIVE_ENCODER_B_PORT 1

		// Gear subsystem
#define GEAR_ENCODER_A_PORT 8
#define GEAR_ENCODER_B_PORT 9

#define GEAR_LIMIT_SWITCH_PORT 6

		// Ultrasonic subsystem
#define ULTRASONIC_TRIGGER_PORT 4
#define ULTRASONIC_ECHO_PORT 5

	//Analog Ports
#define GYRO_PORT 0

// POINTERS
	// Climber subsystem
std::shared_ptr<SpeedController> RobotMap::winchMotor;
std::shared_ptr<Servo> RobotMap::rachetServo;
std::shared_ptr<Servo> RobotMap::climberArm;

	// Drivetrain subsystem
std::shared_ptr<AnalogGyro> RobotMap::gyro;
std::shared_ptr<Encoder> RobotMap::driveEncoder;
std::shared_ptr<SpeedController> RobotMap::frontLeftDrive;
std::shared_ptr<SpeedController> RobotMap::backLeftDrive;
std::shared_ptr<SpeedController> RobotMap::frontRightDrive;
std::shared_ptr<SpeedController> RobotMap::backRightDrive;
std::shared_ptr<RobotDrive> RobotMap::robotDrive;

	// Gear subsystem
std::shared_ptr<Encoder> RobotMap::gearEncoder;
std::shared_ptr<SpeedController> RobotMap::gearMotor;
std::shared_ptr<DigitalInput> RobotMap::gearLimitSwitch;

	// Low ball shooter subsystem
std::shared_ptr<Servo> RobotMap::leftLowBallArm;
std::shared_ptr<Servo> RobotMap::rightLowBallArm;

	// Ultrasonic subsystem
std::shared_ptr<Ultrasonic> RobotMap::ultrasonic;

void RobotMap::init() {
	LiveWindow *lw = LiveWindow::GetInstance();

	// Climber subsystem
	winchMotor.reset(new Victor(WINCH_MOTOR_PORT));
	rachetServo.reset(new Servo(RATCHET_SERVO_PORT));
	climberArm.reset(new Servo(CLIMBER_ARM_PORT));

	// Drivetrain subsystem
	driveEncoder.reset(new Encoder(DRIVE_ENCODER_A_PORT, DRIVE_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
	lw->AddSensor("Drive", "Encoder", driveEncoder);

	backLeftDrive.reset(new Victor(BACK_LEFT_DRIVE_PORT));
	backRightDrive.reset(new Victor(BACK_RIGHT_DRIVE_PORT));
	frontLeftDrive.reset(new Victor(FRONT_LEFT_DRIVE_PORT));
	frontRightDrive.reset(new Victor(FRONT_RIGHT_DRIVE_PORT));

	backRightDrive->SetInverted(false);
	frontRightDrive->SetInverted(false);

	robotDrive.reset(new RobotDrive(frontLeftDrive, backLeftDrive, frontRightDrive, backRightDrive));
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

	// Low ball shooter subsystem
	leftLowBallArm.reset(new Servo(LEFT_LOW_BALL_ARM_PORT));
	rightLowBallArm.reset(new Servo(RIGHT_LOW_BALL_ARM_PORT));

	// Ultrasonic subsystem
	ultrasonic.reset(new Ultrasonic(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_ECHO_PORT));
	lw->AddSensor("Drive", "Ultrasonic", ultrasonic);

	ultrasonic->SetAutomaticMode(true);
}

void RobotMap::reset() {
	Robot::climber->Reset();
	Robot::drivetrain->Reset();
	Robot::gear->Reset();
	Robot::ultrasonicSubsystem->Reset();
}
