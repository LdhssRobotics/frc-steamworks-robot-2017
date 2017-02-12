#ifndef ClimbRope_H
#define ClimbRope_H

#include "../RobotMap.h"
#include "WPILib.h"

class ClimbRope : public Command {
public:
	ClimbRope();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimbRope_H
