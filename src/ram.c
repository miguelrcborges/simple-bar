#include <stdio.h>
#include <sys/sysinfo.h>

int ram(char *buf) {
	struct sysinfo si;
	
	double total_ram, used_ram;

	if (sysinfo(&si))
		return sprintf(buf, " FAILED TO READ RAM ");

	total_ram = (double) si.totalram / (1024 * 1024 * 1024);
	used_ram = (double) (si.totalram - si.freeram - si.bufferram - si.sharedram) / (1024 * 1024);

	if (used_ram < 1000) {
		return sprintf(buf, " %.1fM/%.1fG ", used_ram, total_ram);
	}

	used_ram /= 1024;
	return sprintf(buf, " %.1fG/%.1fG ", used_ram, total_ram);
}
