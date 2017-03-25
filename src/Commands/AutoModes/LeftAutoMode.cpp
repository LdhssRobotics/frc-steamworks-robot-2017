#include "LeftAutoMode.h"
#include "../DriveDistance.h"
#include "../SetHeading.h"
#include "../GearMechanism.h"
#include "../ToggleFrontEnd.h"

LeftAutoMode::LeftAutoMode() {
	AddParallel(new ToggleFrontEnd());
	AddSequential(new DriveDistance(93.307));
	AddSequential(new SetHeading(45));
	AddSequential(new DriveDistance(50));
	AddSequential(new GearMechanism());
	AddSequential(new DriveDistance(-50));
	AddSequential(new SetHeading(-45));
	AddSequential(new DriveDistance(90));
}
