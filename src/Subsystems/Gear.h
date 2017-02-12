#ifndef Gear_H
#define Gear_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Gear : public Subsystem {
private:
	std::shared_ptr<Encoder> gearEncoder;
	std::shared_ptr<Servo> gearServo;

public:
	Gear();
	void InitDefaultCommand();
	void Reset();
};

#endif  // Gear_H
