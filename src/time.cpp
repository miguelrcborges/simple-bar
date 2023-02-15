#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

std::string time() {
  std::stringstream output;
  time_t now = time(NULL);
  struct tm *now_tm = localtime(&now);

  output << std::setfill('0') << std::setw(2) << now_tm->tm_hour << ':' << std::setw(2) << now_tm->tm_min;
  
  return output.str();
}
