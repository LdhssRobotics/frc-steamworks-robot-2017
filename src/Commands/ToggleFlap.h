#ifndef ToggleFlap_H
#define ToggleFlap_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class ToggleFlap : public Command {
public:
	ToggleFlap();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleFlap_H
