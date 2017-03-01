#include "ResetShooter.h"

ResetShooter::ResetShooter()
{

	AddSequential(new CloseBlocker);
	AddSequential(new StopShooters);
	//Super Minty Texturizing Program
}
