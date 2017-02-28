#ifndef Shoot_H
#define Shoot_H

#include "../RobotMap.h"
#include "WPILib.h"

class Shoot : public Command {
public:
	Shoot();
	void ShooterOn();
	void ShooterOff();
	bool IsFinished();
	void Interrupted();
};

#endif  // ClimbRope_H
