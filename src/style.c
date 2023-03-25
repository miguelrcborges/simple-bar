#include "functions.h"
#include <stdio.h>
#include <string.h>

int fg(char *buf, const char *color) {
	return sprintf(buf, "^c#%s^", color);
}

int bg(char *buf, const char *color) {
	return sprintf(buf, "^b#%s^", color);
}

static const char *gap_str = "^f10^";

int gap(char *buf) {
	memcpy(buf, gap_str, 6);
	return 5;
}
