#ifndef DIRECTORY_HANDLER_H
#define DIRECTORY_HANDLER_H

enum {NOT_MATCH, MATCH};
enum {FALSE, TRUE};

void search_match_file(char* path, char* match_string, int max_results);
int directory_match(char* directory_file);
int sub_directory(char* directory_file_name);

#endif