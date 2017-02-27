#ifndef Gear_H
#define Gear_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Gear : public Subsystem {
private:
	std::shared_ptr<Encoder> gearEncoder;
	std::shared_ptr<SpeedController> gearMotor;
	std::shared_ptr<DigitalInput> gearLimitSwitch;

public:
	Gear();
	void SetMotorSpeed(float speed);
	bool InCorrectPosition();
	void ResetEncoder();
	void Reset();
	bool InCorrectReturnPosition();
	float GetPosition();
};

#endif  // Gear_H
