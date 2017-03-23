#ifndef ToggleFrontEnd_H
#define ToggleFrontEnd_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class ToggleFrontEnd : public Command {
public:
	ToggleFrontEnd();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleFrontEnd_H
