#pragma once
#include "Vehicle.h"

#include "RaceLibConnection.h"

class RACELIB_API GroundVehicle : public Vehicle {
private:
	double moving_until_rest;
	double rest_1;
	double rest_2;
	double rest_3;
public:

	GroundVehicle(double speed, std::string name, double moving_until_rest, double rest_1, double rest_2, double rest_3) 
		: Vehicle(speed, name), 
		moving_until_rest(moving_until_rest), 
		rest_1(rest_1), 
		rest_2(rest_2), 
		rest_3(rest_3) {};

    virtual double calculate_time(double distance) {
        double time_needed = distance / speed;
        double moving_time = moving_until_rest;

        int full_cycles = static_cast<int>(time_needed / moving_time);
        double remaining_time = time_needed - full_cycles * moving_time;

        double total_rest_time = 0.0;
        if (full_cycles >= 1) total_rest_time += rest_1;
        if (full_cycles >= 2) total_rest_time += rest_2;
        if (full_cycles > 2)  total_rest_time += (full_cycles - 2) * rest_3;

        return time_needed + total_rest_time;
    }
};
