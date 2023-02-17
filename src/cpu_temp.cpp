#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

std::string cpu_temp() {
  double temperature;
  std::stringstream output;
  std::ifstream file("/sys/class/thermal/thermal_zone2/temp");
  file >> temperature;
  temperature /= 1000;

  output << std::fixed << std::setprecision(0) << temperature << "°C";

  return output.str();
}
