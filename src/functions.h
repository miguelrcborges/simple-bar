#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

/* style.c */
int fg(char *buf, const char *color);
int bg(char *buf, const char *color);
int gap(char *buf);

/* cpu.c */
int cpu_temp(char *buf, int fd);

/* ram.c */
int ram(char *buf);
int ram_htoplike(char *buf, FILE *ram_file);

/* time.c */
int time_min(char *buf);
int time_min_12(char *buf);

/* battery.c */
int battery(char *buf, const char *battery_file);

/* customcommand.c */
int command(char *buf, const char *command);

#endif
