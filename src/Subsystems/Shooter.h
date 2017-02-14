#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem {
private:
	std::shared_ptr<SpeedController> flywheelMotor;
	std::shared_ptr<DigitalInput> shooterLeftLimitSwitch;
	std::shared_ptr<DigitalInput> shooterRightLimitSwitch;
	std::shared_ptr<SpeedController> shooterHorizontalAdjust;
	std::shared_ptr<Servo> shooterVerticalAdjust;
	std::shared_ptr<Servo> ballStopper;
	std::shared_ptr<Encoder> flywheelEncoder;

public:
	Shooter();
	void Reset();
};

#endif  // Shooter_H
