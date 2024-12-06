#pragma once
#include <string>

#include "RaceLibConnection.h"

class RACELIB_API Vehicle {
public:
	std::string name;
	double speed;
	Vehicle(double speed, std::string name) : speed(speed), name(name) {
		
	};
};