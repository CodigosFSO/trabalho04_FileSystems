#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "directory_handler.h"

int main(int argc, char* argv[]) 
{
	if(argc >= 4) {
		char* path = malloc(strlen(argv[1]) + 2);
		path[0] = '.';

		strcat(path, argv[1]);
	
		search_match_file(path, argv[2], atoi(argv[3]));

		free(path);
	}
	else {
		printf("numero de argumentos insuficiente\n");
	}

	return 0;
}