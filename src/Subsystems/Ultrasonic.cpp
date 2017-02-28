/*
 * Ultrasonic.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: programmer
 */

#include <Subsystems/Ultrasonic.h>
#include "../RobotMap.h"
#include "../Robot.h"
#include "Ultrasonic.h"
#include "WPILib.h"

Ultrasonic::Ultrasonic(): Subsystem ("Ultrasonic"){
	// TODO Auto-generated constructor stub

}

void Ultrasonic::GetRange(){
	int range = Robot::ultrasonic->GetRangeInches();
	SmartDashboard::PutNumber("Distance: ", range);


}
void Ultrasonic::Reset(){

}
