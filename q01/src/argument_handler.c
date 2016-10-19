#include "argument_handler.h"
#include <time.h>
#include <string.h>

time_t convert_argument_to_time(char* argument)
{
	struct tm time;
	time_t time_converted;
	int error;

	char year[5];
	char month[3];
	char day[3];
	char hours[3];
	char minutes[3];

	strncpy(year, argument, YEAR_END);
	strncpy(month, argument + YEAR_END, MONTH_END - YEAR_END);
	strncpy(day, argument + MONTH_END, DAY_END - MONTH_END);
	strncpy(hours, argument + DAY_END, HOURS_END - DAY_END);
	strncpy(minutes, argument + HOURS_END, MINUTES_END - HOURS_END);

	time.tm_year = atoi(year) - 1900;
	time.tm_mon = atoi(month) - 1;
	time.tm_mday = atoi(day);
	time.tm_hour = atoi(hours);
	time.tm_min = atoi(minutes);

	time_converted = mktime(&time);

	if(time_converted == -1) {
		printf("Ocorreu um erro na conversão\n");
	}
	
	return time_converted;
}
