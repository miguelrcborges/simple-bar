#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

#define gap "^f10^"
#define fg(color) "^c#" color "^"
#define bg(color) "^b#" color "^"

std::string time_min();
std::string time_wdate();
std::string battery();
std::string ram();
std::string ram_htoplike();
std::string cpu_temp();

#endif
