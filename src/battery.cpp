#include <fstream>
#include <sstream>

std::string battery() {
	std::ifstream file("/sys/class/power_supply/BATT/capacity");
	std::stringstream output;
	int battery;
	file >> battery;
	output << battery << '%';
	return output.str();
}
