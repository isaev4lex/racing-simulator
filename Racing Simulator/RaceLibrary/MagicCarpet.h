#pragma once
#include "AirVehicle.h"

#include "RaceLibConnection.h"

class RACELIB_API MagicCarpet : public AirVehicle {
public:
	double get_modified_dist(double dist) override {
		if (dist < 1000) {
			return dist;
		}
		else if (dist < 5000) {
			return dist * 0.97;
		}
		else if (dist < 10000) {
			return dist * 0.9;
		}
		else {
			return dist * 0.95;
		}
	}

	MagicCarpet() : AirVehicle(10, "Ковёр-самолёт") {

	};
};