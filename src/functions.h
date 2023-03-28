#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* style.c */
int fg(char *buf, const char *color);
int bg(char *buf, const char *color);
int gap(char *buf);

/* cpu.c */
int cpu_temp(char *buf, const char *file);

/* ram.c */
int ram(char *buf);
int ram_htoplike(char *buf);

/* time.c */
int time_min(char *buf);
int time_min_12(char *buf);

/* battery.c */
int battery(char *buf, const char *battery_file);

/* customcommand.c */
int command(char *buf, const char *command);

#endif
