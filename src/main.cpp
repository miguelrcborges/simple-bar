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
    output = fg("282828");
		output += bg("e78a4e");
		output += ' ' + cpu_temp() + ' ' + gap + bg("a9b665") + ' ' + ram() +  ' ' + gap + bg("7daea3") + ' ' + time() + ' ' + gap;
		if (XStoreName(disp, DefaultRootWindow(disp), output.c_str()) < 0) {
			std::cout << "Failed to allocate memory\n";
			return -1;
		} else {
			XFlush(disp);
		}
		sleep(5);
	}
	return 0;
}
