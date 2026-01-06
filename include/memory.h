//Only memory stuff should be here
#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>

#define MEMINFO_PATH     "/proc/meminfo"

//Prints PC's total memory
char* trim_leading_spaces(char *str);
void print_mem_total();

#endif