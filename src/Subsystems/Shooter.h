#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem {
private:
	std::shared_ptr<SpeedController> flywheelMotor1;
	std::shared_ptr<SpeedController> flywheelMotor2;
	std::shared_ptr<DigitalInput> shooterLeftLimitSwitch;
	std::shared_ptr<DigitalInput> shooterRightLimitSwitch;
	std::shared_ptr<SpeedController> shooterHorizontalMotor;
	std::shared_ptr<Servo> shooterFlap;
	std::shared_ptr<Servo> ballStopper;
	std::shared_ptr<Encoder> flywheelEncoder1;
	std::shared_ptr<Encoder> flywheelEncoder2;

public:
	Shooter();
	void Reset();

	void SetFlapAngle(float flapAngle);
	void CloseBlocker();
	void OpenBlocker();
	void StartFlyWheelMotors();
	void StopFlyWheelMotors();
	void MoveHorizontalMotor(float horizontalMotorSpeed);
};

#endif  // Shooter_H
