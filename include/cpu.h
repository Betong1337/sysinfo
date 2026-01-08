//Only cpu stuff should be here
#ifndef CPU_H 
#define CPU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>
#include <defines.h>

#define CPUINFO_PATH     "/proc/cpuinfo"

//Prints CPU model
void print_cpu_model();

#endif