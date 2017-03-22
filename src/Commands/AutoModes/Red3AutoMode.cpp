#include "Red3AutoMode.h"
#include "../DriveDistance.h"
#include "../SetHeading.h"
#include "../GearMechanism.h"

Red3AutoMode::Red3AutoMode() {
	AddSequential(new DriveDistance(93.307));
	AddSequential(new SetHeading(45));
	AddSequential(new DriveDistance(50));
	AddSequential(new GearMechanism());
	AddSequential(new DriveDistance(-50));
	AddSequential(new SetHeading(-45));
	AddSequential(new DriveDistance(90));
}
