//Only memory stuff should be here
#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>
#include <color.h>

#define MEMINFO_PATH     "/proc/meminfo"

#define MEM_PREFIX "Memory: "
#define MEM_MSG "%s%s%s%.2f GB / %.2f GB (%s%d%%%s)\n"
#define SWAP_PREFIX "Swap: "

#define MEM_TOTAL_CMP "MemTotal"
#define MEM_AVAILABLE_CMP "MemAvailable"
#define SWAP_TOTAL_CMP "SwapTotal"
#define SWAP_FREE_CMP "SwapFree"
#define SWAP_CACHED_CMP "SwapCached"

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