#include <vector>
#include "RaceLibConnection.h"
#include "AirVehicle.h"

class AirRace {
private:
	std::vector<AirVehicle*> air_vehicle_vector;
	std::vector<float> time;
	int distance;
protected:
public:
	void set_air_vehicle_vector(std::vector<AirVehicle*> new_air_vehicle_vector) {
		air_vehicle_vector = new_air_vehicle_vector;
	}
	
	void set_distance(int distance) {
		this->distance = distance;
	}

	void calculate_time() {
		time.resize(air_vehicle_vector.size());
		for (int i = 0; i != air_vehicle_vector.size(); i++) {
			time[i] = air_vehicle_vector[i]->get_modified_dist(distance) / air_vehicle_vector[i]->speed;
		}
	}

	std::vector<float> get_time() {
		return time;
	}
};