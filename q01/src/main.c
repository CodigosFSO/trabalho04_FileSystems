#include <stdio.h>
#include <utime.h>
#include <sys/stat.h>
#include <time.h>

#include "argument_handler.h"
#include "backup.h"

int main(int argc, char* argv[])
{
	struct utimbuf new_meta;
	time_t time_to_set;

	create_backup(argv[1]);

	time_to_set = convert_argument_to_time(argv[2]);

	new_meta.actime = time_to_set;
	new_meta.modtime = time_to_set;

	if(utime(argv[1], &new_meta) < 0) {
		perror(argv[1]);
		return 1;
	}

	return 0;
}