#include <stdio.h>
#include <stdlib.h>

int cpu_temp(char *buf, const char *file_name) {
	FILE *file = fopen(file_name, "r");
	char read_buf[8];

	if (file == NULL) {
		return sprintf(buf, " FILE NOT FOUND ");
	}

	fgets(read_buf, 8, file);
	fclose(file);
	
	return sprintf(buf, " %d°C ", atoi(read_buf) / 1000);
}
