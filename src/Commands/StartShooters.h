#ifndef StartShooters_H
#define StartShooters_H


#include "../RobotMap.h"
#include "WPILib.h"
#include "../Robot.h"

class StartShooters: public Command
{
public:
	StartShooters();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
