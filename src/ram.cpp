#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <sys/sysinfo.h>

std::string ram() {
	struct sysinfo si;
	std::stringstream output;
	double total_ram, used_ram;

	if (sysinfo(&si))
		return "Error!";

	total_ram = (double) si.totalram / (1024 * 1024 * 1024);
	used_ram = (double) (si.totalram - si.freeram - si.bufferram - si.sharedram) / (1024 * 1024);

	output << std::setprecision(1) << std::fixed << "RAM: " ;
	if (used_ram < 1000) {
		output << used_ram << 'M';
	} else {
		used_ram /= 1024;
		output << used_ram << 'G';
	}
	output << '/' << total_ram << 'G';
	
	return output.str();
}


std::string ram_htoplike() {
	std::ifstream file("/proc/meminfo");
	std::stringstream output;
	double total_ram, free_ram, used_ram, buffered_ram, cached_ram;

	file.ignore(10, ':');
	file >> total_ram;
	file.ignore(100, '\n');

	file.ignore(9, ':');
	file >> free_ram;
	file.ignore(100, '\n');

	file.ignore(100, '\n');

	file.ignore(9, ':');
	file >> cached_ram;
	file.ignore(100, '\n');

	file.ignore(8, ':');
	file >> buffered_ram;
	file.ignore(100, '\n');

	used_ram = total_ram - free_ram - buffered_ram - cached_ram;
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
