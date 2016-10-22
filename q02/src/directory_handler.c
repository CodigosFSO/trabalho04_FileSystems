#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "directory_handler.h"

void search_match_file(char* path, char* match_string, int max_results)
{
	DIR *path_directory;
	struct dirent *directory_file;

	path_directory = opendir(path);

	if(path_directory != NULL) {
		while((directory_file = readdir(path_directory)) != NULL) {
			if(directory_match(directory_file->d_name) && sub_directory(directory_file->d_name)) {
				printf("Diretório atual: %s\t\t Nome do diretório: %s\n", path, directory_file->d_name);
				search_match_file(directory_file->d_name, match_string, max_results);
			}
			else if(sub_directory(directory_file->d_name)){
				printf("Diretório atual: %s\t\t Nome do arquivo: %s\n", path, directory_file->d_name);
			}
		}

		printf("\n\n");

		closedir(path_directory);
	}
	else{
		perror("");
	}
}

int directory_match(char* directory_file_name) 
{
	DIR* path_directory  = opendir(directory_file_name);

	if(path_directory != NULL) {
		return MATCH;
	}
	else {
		return NOT_MATCH;
	}
}

int sub_directory(char* directory_file_name) 
{
	if(strcmp(directory_file_name, ".") != 0 && strcmp(directory_file_name, "..") != 0) {
		return TRUE;
	}
	else{
		return FALSE;
	}
}