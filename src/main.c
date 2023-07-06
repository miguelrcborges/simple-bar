#include <X11/Xlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "functions.h"

static const char *cpu_temp_file_name = "/sys/class/thermal/thermal_zone2/temp";

int main(void) {
	char buf[256];
	Display *disp;
	int cursor = 0;

	int cpu_temp_fd = open(cpu_temp_file_name, O_RDONLY);

	FILE *ram_file = fopen("/proc/meminfo", "r");

	if (!(disp = XOpenDisplay(NULL))) {
		puts("Failed to open display.");
		return 0;
	}

	while (1) {
		cursor += fg(buf, "282828");
		cursor += bg(buf + cursor, "e78a4e");
		cursor += cpu_temp(buf + cursor, cpu_temp_fd);
		cursor += gap(buf + cursor);
		cursor += bg(buf + cursor, "a9b665");
		cursor += ram_htoplike(buf + cursor, ram_file);
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
		sleep(1);
	}

	close(cpu_temp_fd);
	fclose(ram_file);
	return 0;
}
