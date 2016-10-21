#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "argument_handler.h"

time_t convert_argument_to_time(char* argument)
{
	struct tm time;
	time_t time_converted = 0;

	char year[5];
	char month[3];
	char day[3];
	char hours[3];
	char minutes[3];

	if(strlen(argument) >= 12) {

		strncpy(year, argument, YEAR_END);
		strncpy(month, argument + YEAR_END, MONTH_END - YEAR_END);
		strncpy(day, argument + MONTH_END, DAY_END - MONTH_END);
		strncpy(hours, argument + DAY_END, HOURS_END - DAY_END);
		strncpy(minutes, argument + HOURS_END, MINUTES_END - HOURS_END);

		time.tm_year = atoi(year) - 1900;
		time.tm_mon = atoi(month) - 1;
		time.tm_mday = atoi(day);
		time.tm_hour = atoi(hours) - 1;
		time.tm_min = atoi(minutes);
		time.tm_sec = 0;

		//debug(time);

		time_converted = mktime(&time);

		if(time_converted == -1) {
			printf("Ocorreu um erro na conversão\n");
		}
	}
	else {
		printf("String inválida!\n");
		printf("Digite uma string no formato AAAAMMDDHHmm\n");
	}
	
	return time_converted;
}

void debug(struct tm time) {
	printf("Year: %d\n", time.tm_year);
	printf("Month: %d\n", time.tm_mon);
	printf("Day: %d\n", time.tm_mday);
	printf("Hour: %d\n", time.tm_hour);
	printf("Minutes: %d\n", time.tm_min);
}