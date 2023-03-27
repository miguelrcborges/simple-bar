#include <stdio.h>
#include <time.h>

int time_min(char *buf) {
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);

	return sprintf(buf, " %02d:%02d ", now_tm->tm_hour, now_tm->tm_min);
}

int time_min_12(char *buf) {
	char *half;
	int hour;
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);

	if (now_tm->tm_hour >= 12) {
		half = "PM";
		hour = now_tm->tm_hour - 12;
	} else {
		half = "AM";
		if (now_tm->tm_hour == 0) hour = 12;
		else hour = now_tm->tm_hour;
	}


	return sprintf(buf, " %02d:%02d %s ", hour, now_tm->tm_min, half);
}
