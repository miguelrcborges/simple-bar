#include <stdio.h>
#include <stdlib.h>

int battery(char *buf, const char *file_name) {
	FILE *file = fopen(file_name, "r");
	char read_buf[4];

	if (file == NULL) {
		return sprintf(buf, " BATTERY FILE NOT FOUND ");
	}

	fgets(read_buf, 4, file);
	fclose(file);

	return sprintf(buf, " %d%%", atoi(read_buf));
}
