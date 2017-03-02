#ifndef DriveDistance_H
#define DriveDistance_H

#include "../Robot.h"
#include <WPILib.h>

class DriveDistance : public Command {
private:

	float mspeed;
	float duration;
public:
	DriveDistance(float speed, float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveDistance_H
