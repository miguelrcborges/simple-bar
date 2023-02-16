#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

#define gap "^f10^"

std::string time();
std::string battery();
std::string fg(std::string color);
std::string bg(std::string color);
std::string ram();
std::string cpu_temp();

#endif
