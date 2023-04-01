#include <stdio.h>
#include <X11/Xlib.h>
#include <unistd.h>

#include "functions.h"

static const char *temperature_file = "/sys/class/thermal/thermal_zone2/temp";

int main(void) {
	char buf[256];
	Display *disp;
	int cursor = 0;

	if (!(disp = XOpenDisplay(NULL))) {
		puts("Failed to open display.");
		return 0;
	}

	while (1) {
		cursor += fg(buf, "282828");
		cursor += bg(buf + cursor, "e78a4e");
		cursor += cpu_temp(buf + cursor, temperature_file);
		cursor += gap(buf + cursor);
		cursor += bg(buf + cursor, "a9b665");
		cursor += ram_htoplike(buf + cursor);
		cursor += gap(buf + cursor);
		cursor += bg(buf + cursor, "7daea3");
		cursor += time_min(buf + cursor);
		cursor += gap(buf + cursor);

		if (XStoreName(disp, DefaultRootWindow(disp), buf) < 0) {
			puts("Failed to allocate memory");
			return -1;
		} else {
			XFlush(disp);
		}
		cursor = 0;
		sleep(5);
	}
	return 0;
}
