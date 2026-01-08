//Only memory stuff should be here
#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>
#include <defines.h>

#define MEMINFO_PATH     "/proc/meminfo"

char* trim_leading_spaces(char *str);
//Returns memory info from /proc/meminfo
char* get_memory_info(char *option);
//Returns percentage color.
char *get_percentage_color(int used_percent);
//Prints used ram ATM and total ram
void print_mem_total();
//Prints used swap ATM and total ram
void print_swap();



#endif