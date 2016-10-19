#include <stdio.h>
#include <utime.h>
#include <sys/stat.h>
#include <time.h>

#include "argument_handler.h"


int main(int argc, char* argv[])
{
	struct stat target_stat;
	struct utimbuf new_times;
	time_t time_to_set;
	stat(argv[1], &target_stat);

	time_to_set = convert_argument_to_time(argv[2]);

	printf("%s", asctime(gmtime(&time_to_set)));
	return 0;
}