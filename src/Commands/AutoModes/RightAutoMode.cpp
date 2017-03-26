#include <Commands/AutoModes/RightAutoMode.h>
#include "../DriveDistance.h"
#include "../SetHeading.h"
#include "../GearMechanism.h"
#include "../ToggleFrontEnd.h"

RightAutoMode::RightAutoMode() {
	AddParallel(new ToggleFrontEnd());
	AddSequential(new DriveDistance(100));
//	AddSequential(new SetHeading(-45));
//	AddSequential(new DriveDistance(20));
//	AddSequential(new GearMechanism());
//	AddSequential(new DriveDistance(-50));
//	AddSequential(new SetHeading(45));
//	AddSequential(new DriveDistance(90));
}
