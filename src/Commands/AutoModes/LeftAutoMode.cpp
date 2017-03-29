#include "LeftAutoMode.h"
#include "../DriveDistance.h"
#include "../SetHeading.h"
#include "../GearMechanism.h"
#include "../ToggleFrontEnd.h"

LeftAutoMode::LeftAutoMode() {
	// Deliver a gear and drive to centre field
	AddParallel(new ToggleFrontEnd());
	AddSequential(new DriveDistance(60));
	AddSequential(new SetHeading(45));
	AddSequential(new DriveDistance(20));
	AddSequential(new GearMechanism());
	AddSequential(new DriveDistance(-50));
	AddSequential(new SetHeading(-45));
	AddSequential(new DriveDistance(90));
}
