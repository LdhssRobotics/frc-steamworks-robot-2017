#ifndef CatchRope_H
#define CatchRope_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class CatchRope : public Command {
public:
	CatchRope();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CatchRope_H
