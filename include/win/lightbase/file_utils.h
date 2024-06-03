#pragma once
#include <sys/stat.h>
#include <sys/types.h>

#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <win/dirent/dirent.h>

void make_directory(const char *directory);
char **get_filenames(const char *directory, int *count);
char **get_foldernames(const char *directory, int *count);
void free_filenames(char **filenames, int count);
void free_foldernames(char **filenames, int count);
bool is_file_exist(const char *path);
