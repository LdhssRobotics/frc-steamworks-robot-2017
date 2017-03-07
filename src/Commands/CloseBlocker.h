#ifndef CloseBlocker_H
#define CloseBlocker_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class CloseBlocker: public Command
{
public:
	CloseBlocker();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
