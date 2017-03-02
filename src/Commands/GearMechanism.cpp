#include "GearMechanism.h"
#include "Commands/PlaceGear.h"
#include "Commands/GoBackGear.h"

GearMechanism::GearMechanism() {
	AddSequential(new PlaceGear());
	AddSequential(new GoBackGear());
}
