#ifndef OpenBlocker_H
#define OpenBlocker_H
#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class OpenBlocker: public Command
{
public:
	OpenBlocker();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
