#ifndef CollectGear_H
#define CollectGear_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class CollectGear : public Command {
public:
	CollectGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CollectGear_H
