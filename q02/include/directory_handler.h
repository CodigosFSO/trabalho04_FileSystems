#ifndef DIRECTORY_HANDLER_H
#define DIRECTORY_HANDLER_H

enum {NOT_MATCH, MATCH};
enum {FALSE, TRUE};

void search_match_file(char* path, char* match_string, int* max_results, char* father_directory, 
	int* current_result);
int directory_match(char* directory_file);
int sub_directory_or_file(char* directory_file_name);
void print_file(char* file_path);
char* build_total_path(char* infix, char* path);
int compare_match_string(char* match_string, char* file_name);

#endif