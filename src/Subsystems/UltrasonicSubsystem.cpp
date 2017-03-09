/*
 * UltrasonicSystem.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: programmer
 */

#include "UltrasonicSubsystem.h"
#include "Commands/GetUltrasonic.h"
#include "../RobotMap.h"
#include "../Robot.h"

UltrasonicSubsystem::UltrasonicSubsystem(): Subsystem ("UltrasonicSubsystem"){
	ultrasonic = RobotMap::ultrasonic;
}

void UltrasonicSubsystem::InitDefaultCommand() {
	// Data from the ultrasonic will be sent the whole time the program is running
	SetDefaultCommand(new GetUltrasonic());
}

void UltrasonicSubsystem::Log(){
	// Return distance in inches and feet
	SmartDashboard::PutNumber("Distance-inches: ", ultrasonic->GetRangeInches());
	SmartDashboard::PutNumber("Distance-feet: ", (ultrasonic->GetRangeInches() * 0.0833333));
}

float UltrasonicSubsystem::GetRangeInches() {
	return ultrasonic->GetRangeInches();
}

void UltrasonicSubsystem::Reset(){

}
