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

int ram_htoplike(char* buf, FILE *file) {
	fflush(file);
	rewind(file);

	double total, free, used, buffered, cached;

	char label[64];
	fscanf(file, "%63s %lf kB\n", label, &total);
	fscanf(file, "%63s %lf kB\n", label, &free);
	fscanf(file, "%*[^\n]\n");
	fscanf(file, "%63s %lf kB\n", label, &buffered);
	fscanf(file, "%63s %lf kB\n", label, &cached);

	used = total - free - buffered - cached;
	used /= 1024;
	total /= 1024 * 1024;

	
	if (used < 1000)
		return sprintf(buf, " %.1fM/%.1fG ", used, total);

	return sprintf(buf, " %.1fG/%.1fG ", used/1024, total);
}
