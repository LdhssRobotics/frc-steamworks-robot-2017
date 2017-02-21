#ifndef PlaceGear_H
#define PlaceGear_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class PlaceGear : public Command {

public:
	PlaceGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PlaceGear_H
