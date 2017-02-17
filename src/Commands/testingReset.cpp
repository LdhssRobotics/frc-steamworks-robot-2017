/*
 * testingReset.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: programmer
 */
#include "testingReset.h"

testingReset::testingReset(){
	Requires(Robot::gear.get());
}

void testingReset::Initialize(){
	Robot::gear->ResetEncoder();
}

void testingReset::Execute(){

}

void testingReset::Interrupted(){

}

bool testingReset::IsFinished(){
	return true;
}

void testingReset::End(){
}






