#ifndef LineUpGear_H
#define LineUpGear_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class LineUpGear : public Command {
public:
	LineUpGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LineUpGear_H
