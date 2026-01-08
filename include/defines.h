#ifndef OUTPUT_H
#define OUTPUT_H

#define SYSINFO_VERSION "0.1"
#define SYSINFO_VERSION_MSG "sysinfo v0.1\n"
//Colors
#define RED "\033[1;31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define HEADER "\033[1;34m"

//memory.c
#define MEM_PREFIX "Memory: "
#define MEM_MSG "%s%s%s%.2f GB / %.2f GB (%s%d%%%s)\n"
#define SWAP_PREFIX "Swap: "

#define MEM_TOTAL_CMP "MemTotal"
#define MEM_AVAILABLE_CMP "MemAvailable"
#define SWAP_TOTAL_CMP "SwapTotal"
#define SWAP_FREE_CMP "SwapFree"
#define SWAP_CACHED_CMP "SwapCached"

//cpu.c
#define CPU_PREFIX "CPU: "
#define CPU_MODEL_NAME "model name"
#define CPU_MSG "%s%s%s%s"

//sysinfo.c
#define PRINT_TITLE_MSG "%s=== %s@%s ===%s\n"

#define UPTIME_PREFIX "Uptime:"
#define UPTIME_MSG1 "%s%s%s %d Hours, %d Minutes\n"
#define UPTIME_MSG2 "%s%s%s %d Days, %d Hour(s), %d Minutes\n"
#define UPTIME_MSG3 "%s%s%s %d Minutes\n"

#define KERNEL_VER_PREFIX "Kernel Version: "
#define KERNEL_MSG "%s%s%s%s\n"

#define OS_PREFIX "OS: "
#define OS_MSG "%s%s%s%s %s\n"
#define OS_NAME_CMP "NAME"
#define OS_VERSION_CMP "VERSION"

//main.c
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

#endif
