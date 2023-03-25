#include <stdio.h>
#include <time.h>

int time_min(char *buf) {
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);

	return sprintf(buf, " %d:%d ", now_tm->tm_hour, now_tm->tm_min);
}
