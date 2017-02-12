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
	void SetMotorSpeed(float speed); // Sets the motor speed
	bool InCorrectPosition(); // Check if gear mechanism is at correct angle
	void Reset(); // Pull gear mechanism in until limit switch is triggered
};

#endif  // Gear_H
