#include <stdio.h>

int command(char *buf, const char *command) {
	FILE *f = popen(command, "r");

	if (!f) {
		return sprintf(buf, " FAILED TO RUN %s ", command);
	}

	buf[0] = ' ';

	int c = 1;
	while ((buf[c] = fgetc(f)) != '\n') {
		++c;
	}
	buf[c] = ' ';

	fclose(f);
	
	return c + 1;
}
