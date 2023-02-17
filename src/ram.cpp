#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

std::string ram() {
	std::ifstream file("/proc/meminfo");
	std::stringstream output;
	double total_ram, available_ram, used_ram;
	file.ignore(10, ':');
	file >> total_ram;

	file.ignore(100, '\n');
	file.ignore(100, '\n');
	file.ignore(14, ':');
	file >> available_ram;

	used_ram = total_ram - available_ram;
	used_ram /= 1024;
	total_ram /= 1024 * 1024;

	output << "RAM: " << std::setprecision(1) << std::fixed;

	if (used_ram < 1000)
		output << used_ram << "M/";
	else {
		used_ram /= 1024;
		output << used_ram << "G/";
	}

	output << total_ram << 'G';


	return output.str();
}
