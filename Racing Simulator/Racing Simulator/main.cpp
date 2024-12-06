#include <iostream>
#include "UI.h"

int main() {
	setlocale(LC_ALL, "Russian");

	UIinterface ui_object;
	ui_object.start_race();

	return 0;
}