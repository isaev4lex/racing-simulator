#pragma once

#include <vector>
#include "RaceLibConnection.h"
#include "GroundVehicle.h"

class GroundRace {
private:
    std::vector<GroundVehicle*> ground_race_vector;
    std::vector<float> time;
    int distance;

public:
    void set_ground_vehicle_vector(std::vector<GroundVehicle*> new_ground_race_vector) {
        ground_race_vector = new_ground_race_vector;
    }

    void set_distance(int distance) {
        this->distance = distance;
    }

    void calculate_time() {
        time.resize(ground_race_vector.size());
        for (int i = 0; i != ground_race_vector.size(); i++) {
            time[i] = ground_race_vector[i]->calculate_time(distance);
        }
    }

    std::vector<float> get_time() {
        return time;
    }

    ~GroundRace() {
        for (auto vehicle : ground_race_vector) {
            delete vehicle;
        }
    }
};
