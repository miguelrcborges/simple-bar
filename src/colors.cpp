#include <string>

std::string fg(std::string color) {
  return "^c#" + color + '^';
}

std::string bg(std::string color) {
  return "^b#" + color + '^';
}
