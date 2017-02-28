#ifndef AimShooter_H
#define AimShooter_H

#include "../RobotMap.h"
#include "WPILib.h"
#include "../Robot.h"

class AimShooter: public Command
{
public:
	AimShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
