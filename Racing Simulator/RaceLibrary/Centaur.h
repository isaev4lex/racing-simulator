#pragma once
#include "GroundVehicle.h"

#include "RaceLibConnection.h"

class RACELIB_API Centaur : public GroundVehicle {
public:
	Centaur() : GroundVehicle(15, "Кентавр", 8, 2, 2, 2) {

	};
};