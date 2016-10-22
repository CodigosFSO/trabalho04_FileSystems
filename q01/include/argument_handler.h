#define YEAR_END 4
#define MONTH_END 6
#define DAY_END 8
#define HOURS_END 10
#define MINUTES_END 12

#include <sys/stat.h>

time_t convert_argument_to_time(char* argument);
void debug(struct tm time);