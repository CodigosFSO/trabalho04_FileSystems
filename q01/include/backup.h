#ifndef BACKUP_H
#define BACKUP_H

void create_backup(char* filename);
char* generate_backup_name(char* filename);
void copy_file(char* filename, char* backup_name);
void print_file_stats(struct stat* target_stat);

#endif