#include <fstream>
#include <string>

std::string battery() {
	std::ifstream file("/sys/class/power_supply/BATT/capacity");
	std::string output;

	if (file.is_open()) {
		int battery;
		file >> battery;
		output = std::to_string(battery) + '%';
		file.close();
	} else {
		output = "N/A";
	}

	return output;
}
