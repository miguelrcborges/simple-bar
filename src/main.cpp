#include <iostream>
#include <X11/Xlib.h>
#include <unistd.h>
#include "functions.h"

int main(void) {
  Display *disp;
  std::string output;

  if (!(disp = XOpenDisplay(NULL))) {
    std::cout << "Failed to open display.\n";
    return 0;
  }

  while (true) {
    output = fg("1e1e2e") + gap + bg("cba6f7") + ' ' + cpu_temp() + ' ' + gap + bg("f38ba8") + ' ' + ram() +  ' ' + gap + bg("74c7ec") + ' ' + time() + ' ' + gap;
    if (XStoreName(disp, DefaultRootWindow(disp), output.c_str()) < 0) {
      std::cout << "Failed to allocate memory";
      return -1;
    } else {
      XFlush(disp);
    }
    sleep(5);
  }
  return 0;
}
