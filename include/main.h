#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>

#include <cpu.h>
#include <memory.h>
#include <sysinfo.h>
#include <gpu.h>

#define USAGE_MSG "Usage: [--cpu | --gpu | --mem | --swap | --all | --uptime | --version | --help]\n"

#define CPU_ARGV_CMP "--cpu"
#define MEM_ARGV_CMP "--mem"
#define SWAP_ARGV_CMP "--swap"
#define ALL_ARGV_CMP "--all"
#define UPTIME_ARGV_CMP1 "--uptime"
#define UPTIME_ARGV_CMP2 "--up"
#define SYSINFO_VERSION_ARGV_CMP1 "--version"
#define SYSINFO_VERSION_ARGV_CMP2 "-v"
#define OS_ARGV_CMP "--os"
#define HELP_ARGV_CMP "--help"
#define KERNEL_VERSION_ARGV_CMP "--kernel-version"
#define GPU_ARGV_CMP "--gpu"

void print_all();
#endif