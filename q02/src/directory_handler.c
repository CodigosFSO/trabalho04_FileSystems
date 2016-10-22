#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "directory_handler.h"

void search_match_file(char* path, char* match_string, int max_results, char* father_directory)
{
	DIR *path_directory;
	struct dirent *directory_file;
	char* total_path = malloc(strlen(path) + strlen(father_directory) + 2);

	strcpy(total_path, father_directory);
	strcat(total_path, "/");
	strcat(total_path, path);

	path_directory = opendir(total_path);

	if(path_directory != NULL) {
		while((directory_file = readdir(path_directory)) != NULL) {
			if(sub_directory_or_file(directory_file->d_name)) {
				printf("\n");
				char* total_file_name;

				total_file_name = malloc(strlen(total_path) + strlen(directory_file->d_name) + 2);

				strcpy(total_file_name, total_path);
				strcat(total_file_name, "/");
				strcat(total_file_name, directory_file->d_name);

				printf("Diretório atual: %s\n", total_path);
				if(directory_match(total_file_name)) {
					printf("Nome do diretório: %s\n", directory_file->d_name);
					search_match_file(directory_file->d_name, match_string, max_results, total_path);
				}
				else if(sub_directory_or_file(directory_file->d_name)){
					print_file(total_file_name);
				}
				free(total_file_name);
			}
		}
		closedir(path_directory);
	}
	else{
		perror("");
	}
	printf("Dando free %s\n\n", total_path);
	free(total_path);
}

int directory_match(char* directory_file_name) 
{
	printf("lendo: %s\n", directory_file_name);
	DIR* path_directory  = opendir(directory_file_name);

	if(path_directory != NULL) {
		printf("É um diretorio\n");
		return MATCH;
	}
	else {
		printf("É um arquivo\n");
		closedir(path_directory);
		return NOT_MATCH;
	}
}

int sub_directory_or_file(char* directory_file_name) 
{
	if(strcmp(directory_file_name, ".") != 0 && strcmp(directory_file_name, "..") != 0) {
		return TRUE;
	}
	else{
		return FALSE;
	}
}

void print_file(char* file_path)
{
	FILE* file;

	file = fopen(file_path, "r");
}