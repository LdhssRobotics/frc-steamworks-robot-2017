#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem {
private:
	std::shared_ptr<SpeedController> shooterHorizontalAdjust;
	std::shared_ptr<SpeedController> shooterFlywheelVictor;
	std::shared_ptr<DigitalInput> shooterLimitSwitch1;
	std::shared_ptr<DigitalInput> shooterLimitSwitch2;
	std::shared_ptr<Servo> shooterVerticalAdjust;
	std::shared_ptr<Servo> shooterBallStopper;

public:
	Shooter();
	void InitDefaultCommand();
};

#endif  // Shooter_H
