#pragma once
#include "GroundVehicle.h"

#include "RaceLibConnection.h"

class RACELIB_API CamelFastWalker : public GroundVehicle {
public:
	CamelFastWalker() : GroundVehicle(40, "Верблюд-быстроход", 10, 5, 6.5, 8) {

	};
};