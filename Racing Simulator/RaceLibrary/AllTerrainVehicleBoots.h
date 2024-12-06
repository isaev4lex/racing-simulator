#pragma once
#include "GroundVehicle.h"

#include "RaceLibConnection.h"

class RACELIB_API AllTerrainVehicleBoots : public GroundVehicle {
public:
	AllTerrainVehicleBoots() : GroundVehicle(6, "Ботинки-вездеходы", 60, 10, 5, 5) {

	};
};