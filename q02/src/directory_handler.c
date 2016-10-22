#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "directory_handler.h"

void search_match_file(char* path, char* match_string, int* max_results, char* father_directory,
	int* current_result)
{
	DIR *path_directory;
	struct dirent *directory_file;
	char* total_path = build_total_path(father_directory, path);

	path_directory = opendir(total_path);

	if(path_directory != NULL) {
		while((directory_file = readdir(path_directory)) != NULL) {
			if(*max_results <= *current_result) {
				return;
			}
			if(sub_directory_or_file(directory_file->d_name)) {
				printf("\n");
				char* total_file_name;

				total_file_name = build_total_path(total_path, directory_file->d_name);

				if(directory_match(total_file_name)) {
					search_match_file(directory_file->d_name, match_string, max_results, total_path,
						current_result);
				}
				else if(sub_directory_or_file(directory_file->d_name)){
					(*current_result)++;
					printf("%d", *current_result);
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
	free(total_path);
}

int directory_match(char* directory_file_name) 
{
	DIR* path_directory  = opendir(directory_file_name);

	if(path_directory != NULL) {
		return MATCH;
	}
	else {
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

	if(file == NULL) {
		printf("Error opening file %s\n", file_path);
	}
	else {
		printf("%s\n", file_path);
		int counter = 0;
		char c;
		while(counter < 30) {
			c = fgetc(file);
			if(c == EOF) {
				break;
			}
			printf("%c", c);
			counter++;
		}
		printf("\n");
	}
}

char* build_total_path(char* infix, char* path)
{
	char* final_path = malloc(strlen(infix) + strlen(path) + 2);
	strcpy(final_path, infix);
	strcat(final_path, "/");
	strcat(final_path, path);

	return final_path;
}