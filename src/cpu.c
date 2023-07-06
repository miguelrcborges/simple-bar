#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int cpu_temp(char *buf, int fd) {
	char read_buf[8];

	if (fd == -1) {
		return sprintf(buf, " FILE NOT FOUND ");
	}

	read(fd, read_buf, 7);
	lseek(fd, 0, SEEK_SET);

	return sprintf(buf, " %d°C ", atoi(read_buf) / 1000);
}
