#ifndef StopShooters_H
#define StopShooters_H


#include "../RobotMap.h"
#include "WPILib.h"
#include "../Robot.h"


class StopShooters: public Command
{
public:
	StopShooters();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
