#include <utime.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "backup.h"


void create_backup(char* filename) {
	struct stat target_stat;
	struct utimbuf target_meta;

	char* backup_name = generate_backup_name(filename);

	if(stat(filename, &target_stat) < 0) {
		perror(filename);
	}

	print_file_stats(&target_stat);

	copy_file(filename, backup_name);

	target_meta.actime = target_stat.st_atime;
	target_meta.modtime = target_stat.st_mtime;

	if(utime(filename, &target_meta) < 0) {
		perror(filename);
	}

	free(backup_name);

}

char* generate_backup_name(char* filename) {
	char* aux_str;
	char* dot_pos;

	if(filename == NULL) {
		printf("Error on generating backup file. Filename it's NULL!\n");
		return NULL;
	}

	aux_str = malloc(strlen(filename) + 1);

	strcpy(aux_str, filename);
	dot_pos = strrchr(aux_str, '.');

	if(dot_pos != NULL) {
		*dot_pos = '\0';
	}
	else {
		printf("Error on finding dot on filename\n");
	}

	strcat(aux_str, ".bkp");

	return aux_str;
}

void copy_file(char* filename, char* backup_name) {
	FILE* source;
	FILE* backup;
	char c;

	source = fopen(filename, "r");

	if(source == NULL) {
		printf("Error trying to open file\n");
		return;
	}

	backup = fopen(backup_name, "w");

	if(backup == NULL) {
		fclose(source);
		printf("Error creating backup file\n");
		return;
	}

	while((c = fgetc(source)) != EOF) {
		fputc(c, backup);
	}

	printf("Backup sucessfully created\n");

	fclose(source);
	fclose(backup);
}

void print_file_stats(struct stat* target_stat)
{
	printf("Last Acess Time: %s", asctime(gmtime(&(target_stat->st_atime))));
	printf("Last Modified Time: %s", asctime(gmtime(&(target_stat->st_mtime))));
}