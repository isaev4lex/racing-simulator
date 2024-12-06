#pragma once
#include "AirVehicle.h"
#include "RaceLibConnection.h"


class RACELIB_API Broomstick : public AirVehicle {
public:
	double get_modified_dist(double dist) override {
		double koef = floor(dist / 1000);
		return dist * (1 - (koef / 100));
	}

	Broomstick() : AirVehicle(20, "Метла") {

	};
};