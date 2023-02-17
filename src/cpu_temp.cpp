#include <string>
#include <sstream>
#include <fstream>

std::string cpu_temp() {
	int temperature;
	std::ifstream file("/sys/class/thermal/thermal_zone2/temp");
	file >> temperature;
	temperature /= 1000;
	
	std::string output = std::to_string(temperature) + "°C";
	return output;
}
