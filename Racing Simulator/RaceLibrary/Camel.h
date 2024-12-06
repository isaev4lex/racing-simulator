#pragma once
#include "GroundVehicle.h"

#include "RaceLibConnection.h"

class RACELIB_API Camel : public GroundVehicle {
public:
	Camel() : GroundVehicle(10, "Верблюд", 30, 5, 8, 8) {

	};
};