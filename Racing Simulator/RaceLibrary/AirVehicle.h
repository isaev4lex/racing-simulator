#pragma once
#include "Vehicle.h"

#include "RaceLibConnection.h"

class RACELIB_API AirVehicle : public Vehicle {
public:
	virtual double get_modified_dist(double dist) = 0;
	AirVehicle(double speed, std::string name) : Vehicle(speed, name) {};
};
