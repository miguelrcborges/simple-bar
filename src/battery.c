#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int battery(char *buf, int fd) {
	char read_buf[4];

	if (fd == -1) {
		return sprintf(buf, " BATTERY FILE NOT FOUND ");
	}

	read(fd, read_buf, 3);
	lseek(fd, 0, SEEK_SET);

	return sprintf(buf, " %d%% ", atoi(read_buf));
}
