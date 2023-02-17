#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

const char days[7][4] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
const char months[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

std::string time_min() {
	std::stringstream output;
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);
	
	output << std::setfill('0') << std::setw(2) << now_tm->tm_hour << ':' << std::setw(2) << now_tm->tm_min;
  
	return output.str();
}

std::string time_wdate() {
	std::stringstream output;
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);
	
	output << days[now_tm->tm_wday] << ", " << now_tm->tm_mday << ' ' << months[now_tm->tm_mon] << ' ' 
		<< 1900 + now_tm->tm_year
		<< " - "
		<< std::setfill('0') << std::setw(2) << now_tm->tm_hour << ':' << std::setw(2) << now_tm->tm_min;
  
	return output.str();
}
