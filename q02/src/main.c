#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	printf("Declarando variavel\n");
	char* path = malloc(strlen(argv[1]) + 2);

	path[0] = '.';

	printf("path: %s\n", path);
	printf("Argumento: %s\n", argv[1]);
	printf("Concacetando strings\n");

	strcat(path, argv[1]);

	printf("Caminho final: %s\n", path);

	free(path);
	return 0;
}