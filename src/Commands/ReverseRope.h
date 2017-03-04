#ifndef ReverseRope_H
#define ReverseRope_H

#include "../RobotMap.h"
#include "WPILib.h"

class ReverseRope : public Command {
public:
	ReverseRope();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ReverseRope_H
