#include "Blue1AutoMode.h"
#include "../DriveDistance.h"
#include "../SetHeading.h"
#include "../GearMechanism.h"


Blue1AutoMode::Blue1AutoMode() {


	// Add Commands here:
	AddSequential(new DriveDistance(1, 0.58));
	AddSequential(new SetHeading(45));
	AddSequential(new DriveDistance(1, 0.19));
	AddSequential(new DriveDistance(0,0));
	AddSequential(new GearMechanism());
	AddSequential(new DriveDistance(-1, 0.19));
	AddSequential(new SetHeading(-45));
	AddSequential(new DriveDistance(1, 2.37));
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
