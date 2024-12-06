#pragma once
#include "AirVehicle.h"

#include "RaceLibConnection.h"

class RACELIB_API Eagle : public AirVehicle {
public:
	double get_modified_dist(double dist) override {
		return dist * 0.94;
	}
	Eagle() : AirVehicle(8, "Îð¸ë") {

	};
};