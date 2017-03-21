#ifndef ToggleReverseDrive_H
#define ToggleReverseDrive_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class ToggleReverseDrive : public Command {
public:
	ToggleReverseDrive();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleReverseDrive_H
