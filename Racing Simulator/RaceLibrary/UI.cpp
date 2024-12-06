#include "UI.h"
#include "AirVehicle.h"
#include "GroundVehicle.h"

#include "AirRace.h"
#include "Broomstick.h"
#include "Eagle.h"
#include "MagicCarpet.h"

#include "GroundRace.h"
#include "AllTerrainVehicleBoots.h"
#include "Camel.h"
#include "CamelFastWalker.h"
#include "Centaur.h"

#include "AllTypeRace.h"

const short UIinterface::races_count;
const short UIinterface::ground_vehicle_count;
const short UIinterface::air_vehicle_count;
const short UIinterface::mixed_vehicle_count;

bool UIinterface::get_race_type() {
	std::cout << "[+] Добро пожаловать в гоночный симулятор!\n" << std::endl;
	for (int i = 0; i != races_count; i++) {
		std::cout << "\t" << i + 1 << ". " << available_races[i] << std::endl;
	}
	std::cout << "\n[?] Выберите тип гонки >> ";
	std::cin >> choosen_race_type;

	if (choosen_race_type > races_count || choosen_race_type <= 0) {
		return false;
	}
	else {
		choosen_race_type -= 1;
		return true;
	}
}

bool UIinterface::get_distance() {
	std::cout << "[?] Укажите длину дистанции (должна быть положительна) >> ";
	std::cin >> choosen_distance;

	if (choosen_distance <= 0) {
		return false;
	}
	else {
		return true;
	};
}

void UIinterface::register_vehicle() {
	if (exit_game) {
		return;
	}

	switch (choosen_race_type) {

		// Ground Race
	case 0:
		if (choosen_vehicles.size() == ground_vehicle_count) {
			std::cout << "\n\n[!] Вы выбрали максимальное количество доступного наземного траспорта!";
			main_menu();
			return;
		}

		while (true) {
			std::cout << "\n[+] Гонка для наземного траспорта" << std::endl;
			std::cout << "[+] Расстояние: " << choosen_distance << std::endl;

			std::ostringstream oss;
			for (size_t i = 0; i < choosen_vehicles.size(); ++i) {
				oss << choosen_vehicles[i];
				if (i < choosen_vehicles.size() - 1) {
					oss << ", ";
				}
			}

			std::cout << "[+] Зарегестрированные транспортные стредства: " << oss.str() << "\n" << std::endl;

			for (int i = 0; i != ground_vehicle_count; i++) {
				std::cout << "\t" << i + 1 << ". " << available_ground_vehicles[i] << std::endl;
			}
			int users_choice;
			std::cout << "\n[?] Выберите транспорт или 0 для окончания процесса регистрации >> ";
			std::cin >> users_choice;

			if (users_choice > ground_vehicle_count) {
				std::cout << "\n[!] Вы ввели неверное значение! Повторите попытку." << std::endl;
				continue;
			}
			else if (users_choice == 0) {
				main_menu();
				break;
			}
			else {
				bool duplication_happened = false;

				const std::string& chosen_vehicle = available_ground_vehicles[users_choice - 1];
				if (std::find(choosen_vehicles.begin(), choosen_vehicles.end(), chosen_vehicle) != choosen_vehicles.end()) {
					duplication_happened = true;
				}

				if (duplication_happened) {
					std::cout << "\n[!] Транспорт '" << chosen_vehicle << "' уже зарегистрирован!";
				}
				else {
					choosen_vehicles.push_back(chosen_vehicle);
					std::cout << "\n[+] Транспорт '" << chosen_vehicle << "' успешно зарегестрирован!";
					register_vehicle();
					break;
				}
			}
		}
		break;
		// Air Race
	case 1:
		if (choosen_vehicles.size() == air_vehicle_count) {
			std::cout << "\n\n[!] Вы выбрали максимальное количество доступного воздушного траспорта!";
			main_menu();
			return;
		}

		while (true) {
			std::cout << "\n[+] Гонка для воздушного траспорта" << std::endl;
			std::cout << "[+] Расстояние: " << choosen_distance << std::endl;

			std::ostringstream oss;
			for (size_t i = 0; i < choosen_vehicles.size(); ++i) {
				oss << choosen_vehicles[i];
				if (i < choosen_vehicles.size() - 1) {
					oss << ", ";
				}
			}

			std::cout << "[+] Зарегестрированные транспортные стредства: " << oss.str() << "\n" << std::endl;

			for (int i = 0; i != air_vehicle_count; i++) {
				std::cout << "\t" << i + 1 << ". " << available_air_vehicles[i] << std::endl;
			}
			int users_choice;
			std::cout << "\n[?] Выберите транспорт или 0 для окончания процесса регистрации >> ";
			std::cin >> users_choice;

			if (users_choice > air_vehicle_count) {
				std::cout << "\n[!] Вы ввели неверное значение! Повторите попытку." << std::endl;
				continue;
			}
			else if (users_choice == 0) {
				main_menu();
				break;
			}
			else {
				bool duplication_happened = false;

				const std::string& chosen_vehicle = available_air_vehicles[users_choice - 1];
				if (std::find(choosen_vehicles.begin(), choosen_vehicles.end(), chosen_vehicle) != choosen_vehicles.end()) {
					duplication_happened = true;
				}

				if (duplication_happened) {
					std::cout << "\n[!] Транспорт '" << chosen_vehicle << "' уже зарегистрирован!";
				}
				else {
					choosen_vehicles.push_back(chosen_vehicle);
					std::cout << "\n[+] Транспорт '" << chosen_vehicle << "' успешно зарегестрирован!";
					register_vehicle();
					break;
				}
			}
		}
		break;
		// Mixed Race
	case 2:
		if (choosen_vehicles.size() == mixed_vehicle_count) {
			std::cout << "\n\n[!] Вы выбрали максимальное количество доступного воздушного траспорта!";
			main_menu();
			return;
		}

		while (true) {
			std::cout << "\n[+] Гонка для смешанного траспорта" << std::endl;
			std::cout << "[+] Расстояние: " << choosen_distance << std::endl;

			std::ostringstream oss;
			for (size_t i = 0; i < choosen_vehicles.size(); ++i) {
				oss << choosen_vehicles[i];
				if (i < choosen_vehicles.size() - 1) {
					oss << ", ";
				}
			}

			std::cout << "[+] Зарегестрированные транспортные стредства: " << oss.str() << "\n" << std::endl;

			for (int i = 0; i != mixed_vehicle_count; i++) {
				std::cout << "\t" << i + 1 << ". " << available_mixed_vehicles[i] << std::endl;
			}
			int users_choice;
			std::cout << "\n[?] Выберите транспорт или 0 для окончания процесса регистрации >> ";
			std::cin >> users_choice;

			if (users_choice > mixed_vehicle_count) {
				std::cout << "\n[!] Вы ввели неверное значение! Повторите попытку." << std::endl;
				continue;
			}
			else if (users_choice == 0) {
				main_menu();
				break;
			}
			else {
				bool duplication_happened = false;

				const std::string& chosen_vehicle = available_mixed_vehicles[users_choice - 1];
				if (std::find(choosen_vehicles.begin(), choosen_vehicles.end(), chosen_vehicle) != choosen_vehicles.end()) {
					duplication_happened = true;
				}

				if (duplication_happened) {
					std::cout << "\n[!] Транспорт '" << chosen_vehicle << "' уже зарегистрирован!";
				}
				else {
					choosen_vehicles.push_back(chosen_vehicle);
					std::cout << "\n[+] Транспорт '" << chosen_vehicle << "' успешно зарегестрирован!";
					register_vehicle();
					break;
				}
			}
		}
		break;
	}
}

bool UIinterface::main_menu() {
	if (choosen_vehicles.size() < 2) {
		std::cout << "\n[!] Должно быть зарегестрировано хотя бы 2 транспортных средства\n" << std::endl;
	}
	else {
		std::cout << "\n[?] Выберите опцию из списка ниже\n" << std::endl;
	}

	std::cout << "\t1. Зарегестрировать траспорт" << std::endl;

	if (choosen_vehicles.size() >= 2) {
		std::cout << "\t2. Начать гонку" << std::endl;
	};

	std::cout << "\t0. Выйти из игры" << std::endl;

	std::cout << "\n[?] Выберите действие >> ";

	short user_answer;
	std::cin >> user_answer;

	if (user_answer == 0) {
		exit_game = true;
		return exit_game;
	}
	else if (user_answer == 1) {
		register_vehicle();
	}
	else if (user_answer == 2 && choosen_vehicles.size() >= 2) {
		return true;
	}
	else {
		main_menu();
		return true;
	}
}

UIinterface::UIinterface() {
	for (int i = 0; i != mixed_vehicle_count; i++) {
		if (i < ground_vehicle_count) {
			available_mixed_vehicles[i] = available_ground_vehicles[i];
		}
		else {
			available_mixed_vehicles[i] = available_air_vehicles[i - ground_vehicle_count];
		}
	}
};

void UIinterface::start_race() {
	// Get race type
	while (true) {
		if (get_race_type()) {
			break;
		}
		else {
			std::cout << "\n[!] Вы ввели неверное значение! Повторите попытку\n" << std::endl;
			continue;
		}
	}

	// Get distance
	while (true) {
		if (get_distance()) {
			break;
		}
		else {
			std::cout << "\n[!] Вы ввели неверное значение! Повторите попытку\n" << std::endl;
			continue;
		}
	}

	// Main menu
	while (true) {
		if (main_menu()) {
			break;
		}
		else {
			std::cout << "\n[!] Вы ввели неверное значение! Повторите попытку\n" << std::endl;
			continue;
		}
	}

	if (!exit_game) {

		// 0 - ground, 1 - air, 2 - mixedc

		if (choosen_race_type == 0) {
			GroundRace ground_race_obj;
			std::vector<GroundVehicle*> ground_vehicle_vector;

			for (const std::string& i : choosen_vehicles) {
				if (i == "Ботинки-вездеходы") {
					GroundVehicle* all_terrain_boots = new AllTerrainVehicleBoots;
					ground_vehicle_vector.push_back(all_terrain_boots);
				}
				else if (i == "Верблюд") {
					GroundVehicle* camel = new Camel;
					ground_vehicle_vector.push_back(camel);
				}
				else if (i == "Кентавр") {
					GroundVehicle* centaur = new Centaur;
					ground_vehicle_vector.push_back(centaur);
				}
				else if (i == "Верблюд-быстроход") {
					GroundVehicle* camel_fast_walker = new CamelFastWalker;
					ground_vehicle_vector.push_back(camel_fast_walker);
				}
			}

			ground_race_obj.set_ground_vehicle_vector(ground_vehicle_vector);
			ground_race_obj.set_distance(choosen_distance);
			ground_race_obj.calculate_time();
			std::vector<float> ground_calculated_time = ground_race_obj.get_time();

			std::vector<int> ground_indices(ground_vehicle_vector.size());
			for (int i = 0; i < ground_indices.size(); i++) {
				ground_indices[i] = i;
			}

			std::sort(ground_indices.begin(), ground_indices.end(), [&ground_calculated_time](int a, int b) {
				return ground_calculated_time[a] < ground_calculated_time[b];
				});

			std::cout << "[+] Результаты гонки (наземный транспорт):" << std::endl;
			for (int i = 0; i < ground_indices.size(); i++) {
				int index = ground_indices[i];
				std::cout << "\t" << i + 1 << ". " << ground_vehicle_vector[index]->name
					<< ". Время: " << ground_calculated_time[index] << std::endl;
			}
		}
		else if (choosen_race_type == 1) {
			AirRace air_race_obj;
			std::vector<AirVehicle*> air_vehicle_vector = {};

			for (std::string i : choosen_vehicles) {
				if (i == "Метла") {
					AirVehicle* broomstick = new Broomstick;
					air_vehicle_vector.push_back(broomstick);
				}
				else if (i == "Орёл") {
					AirVehicle* eagle = new Eagle;
					air_vehicle_vector.push_back(eagle);
				}
				else if (i == "Ковёр-самолёт") {
					AirVehicle* magic_carpet = new MagicCarpet;
					air_vehicle_vector.push_back(magic_carpet);
				}
			}
			air_race_obj.set_air_vehicle_vector(air_vehicle_vector);
			air_race_obj.set_distance(choosen_distance);
			air_race_obj.calculate_time();

			std::vector<float> air_calculated_time = air_race_obj.get_time();

			std::vector<int> air_indices(air_vehicle_vector.size());
			for (int i = 0; i < air_indices.size(); i++) {
				air_indices[i] = i;
			}

			std::sort(air_indices.begin(), air_indices.end(), [&air_calculated_time](int a, int b) {
				return air_calculated_time[a] < air_calculated_time[b];
				});

			std::cout << "[+] Результаты гонки (воздушный транспорт):" << std::endl;
			for (int i = 0; i < air_indices.size(); i++) {
				int index = air_indices[i];
				std::cout << "\t" << i + 1 << ". " << air_vehicle_vector[index]->name
					<< ". Время: " << air_calculated_time[index] << std::endl;
			}
		}
		else if (choosen_race_type == 2) {
			AirRace air_race_obj;
			GroundRace ground_race_obj;
			std::vector<AirVehicle*> air_vehicle_vector;
			std::vector<GroundVehicle*> ground_vehicle_vector;

			for (std::string i : choosen_vehicles) {
				if (i == "Метла") {
					AirVehicle* broomstick = new Broomstick;
					air_vehicle_vector.push_back(broomstick);
				}
				else if (i == "Орёл") {
					AirVehicle* eagle = new Eagle;
					air_vehicle_vector.push_back(eagle);
				}
				else if (i == "Ковёр-самолёт") {
					AirVehicle* magic_carpet = new MagicCarpet;
					air_vehicle_vector.push_back(magic_carpet);
				}
				else if (i == "Ботинки-вездеходы") {
					GroundVehicle* all_terrain_boots = new AllTerrainVehicleBoots;
					ground_vehicle_vector.push_back(all_terrain_boots);
				}
				else if (i == "Верблюд") {
					GroundVehicle* camel = new Camel;
					ground_vehicle_vector.push_back(camel);
				}
				else if (i == "Кентавр") {
					GroundVehicle* centaur = new Centaur;
					ground_vehicle_vector.push_back(centaur);
				}
				else if (i == "Верблюд-быстроход") {
					GroundVehicle* camel_fast_walker = new CamelFastWalker;
					ground_vehicle_vector.push_back(camel_fast_walker);
				}
			}

			air_race_obj.set_air_vehicle_vector(air_vehicle_vector);
			air_race_obj.set_distance(choosen_distance);
			air_race_obj.calculate_time();
			ground_race_obj.set_ground_vehicle_vector(ground_vehicle_vector);
			ground_race_obj.set_distance(choosen_distance);
			ground_race_obj.calculate_time();

			std::vector<float> ground_calculated_time = ground_race_obj.get_time();
			std::vector<float> air_calculated_time = air_race_obj.get_time();

			std::vector<int> air_indices(air_vehicle_vector.size());
			for (int i = 0; i < air_indices.size(); i++) {
				air_indices[i] = i;
			}

			std::vector<int> ground_indices(ground_vehicle_vector.size());
			for (int i = 0; i < ground_indices.size(); i++) {
				ground_indices[i] = i;
			}

			std::sort(air_indices.begin(), air_indices.end(), [&air_calculated_time](int a, int b) {
				return air_calculated_time[a] < air_calculated_time[b];
				});

			std::sort(ground_indices.begin(), ground_indices.end(), [&ground_calculated_time](int a, int b) {
				return ground_calculated_time[a] < ground_calculated_time[b];
				});

			std::cout << "[+] Общие результаты гонки:" << std::endl;

			for (int i = 0; i < air_indices.size(); i++) {
				int index = air_indices[i];
				std::cout << "\t" << i + 1 << ". " << air_vehicle_vector[index]->name
					<< ". Время: " << air_calculated_time[index] << std::endl;
			}

			for (int i = 0; i < ground_indices.size(); i++) {
				int index = ground_indices[i];
				std::cout << "\t" << i + 1 << ". " << ground_vehicle_vector[index]->name
					<< ". Время: " << ground_calculated_time[index] << std::endl;
			}
		}

		while (true) {
			std::cout << "\n\t1. Провести ещё одну гонку" << std::endl;
			std::cout << "\t2. Выйти" << std::endl;
			std::cout << "[?] Выберите действие >> ";
			int user_answer;
			std::cin >> user_answer;

			if (user_answer == 1) {
				choosen_vehicles.clear();
				UIinterface::start_race();
				break;
			} else if (user_answer == 2) {
				exit_game = true;
				break;
			} else {
				std::cout << "\n[!] Вы ввели неверное значение! Повторите попытку." << std::endl;
				continue;
			}
		}
	}
}