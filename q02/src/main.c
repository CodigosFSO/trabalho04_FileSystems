#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "directory_handler.h"

int main(int argc, char* argv[]) 
{
	if(argc >= 4) {
		int max_prints = atoi(argv[3]);
		int current_result = 0;
		printf("Resultado de buscador -- ''%s'' na pasta %s\n", argv[2], argv[1]);

		if(strcmp(argv[1], "/") != 0) {
			search_match_file(argv[1], argv[2], &max_prints, ".", &current_result);
		}
		else {
			search_match_file("", argv[2], &max_prints, ".", &current_result);
		}
	}
	else {
		printf("numero de argumentos insuficiente\n");
	}

	return 0;
}