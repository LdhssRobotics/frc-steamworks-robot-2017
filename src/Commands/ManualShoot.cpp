#include "ManualShoot.h"

ManualShoot::ManualShoot()
{
	AddSequential(new StartShooters);
	AddSequential(new OpenBlocker);
}
