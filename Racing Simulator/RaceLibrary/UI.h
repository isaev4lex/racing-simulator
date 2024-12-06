#ifndef UI_h
#define UI_h

#include "RaceLibConnection.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

class RACELIB_API UIinterface {
private:
	bool exit_game = false;

	const static short races_count = 3;
	const static short ground_vehicle_count = 4;
	const static short air_vehicle_count = 3;
	const static short mixed_vehicle_count = ground_vehicle_count + air_vehicle_count;

	short choosen_race_type;
	int choosen_distance;
	std::vector<std::string> choosen_vehicles;

	std::string available_races[races_count] = {
		"Гонка для наземного транспорта", // ground
		"Гонка для воздушного транспорта", // air
		"Гонка для наземного и воздушного транспорта" // ground and air
	};

	std::string available_ground_vehicles[ground_vehicle_count] = {
		"Ботинки-вездеходы",
		"Верблюд",
		"Кентавр",
		"Верблюд-быстроход"
	};
	std::string available_air_vehicles[air_vehicle_count] = {
		"Метла",
		"Орёл",
		"Ковёр-самолёт",
	};
	std::string available_mixed_vehicles[mixed_vehicle_count];


	bool get_race_type();

	bool get_distance();

	void register_vehicle();

	bool main_menu();

public:
	UIinterface();

	void start_race();
};

#endif // UI_h