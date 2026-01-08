//Only cpu stuff should be here
#ifndef CPU_H 
#define CPU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>
#include <color.h>

#define CPUINFO_PATH     "/proc/cpuinfo"
#define CPU_PREFIX "CPU: "
#define CPU_MODEL_NAME "model name"
#define CPU_MSG "%s%s%s%s"

//Prints CPU model
void print_cpu_model();

#endif