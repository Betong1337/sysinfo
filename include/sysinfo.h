//Everthing that is not cpu or memory should be here
#ifndef SYSINFO_H
#define SYSINFO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>
#include <color.h>

#define OS_PATH          "/etc/os-release"
#define KERNEL_PATH      "/proc/version"
#define HOSTNAME_PATH    "/proc/sys/kernel/hostname"
#define UPTIME_PATH      "/proc/uptime"

//sysinfo.c
#define SYSINFO_VERSION "1.0.5"
#define SYSINFO_VERSION_MSG "sysinfo"
#define SYSINFO_FORMAT "%s %s\n"

#define PRINT_TITLE_MSG "%s=== %s@%s ===%s\n"
#define ERROR_MSG "%s%s%s%s\n"

#define UPTIME_PREFIX "Uptime:"
#define UPTIME_MSG1 "%s%s%s %d Hours, %d Minutes\n"
#define UPTIME_MSG2 "%s%s%s %d Days, %d Hour(s), %d Minutes\n"
#define UPTIME_MSG3 "%s%s%s %d Minutes\n"
#define UPTIME_ERROR "Error: Could not print uptime..."

#define KERNEL_VER_PREFIX "Kernel: "
#define KERNEL_MSG "%s%s%s%s\n"
#define KERNEL_ERROR "Error: Could not print kernel..."

#define OS_PREFIX "OS: "
#define OS_MSG "%s%s%s%s %s\n"
#define OS_NAME_CMP "NAME"
#define OS_VERSION_CMP "VERSION"
#define OS_ERROR "Error: Could not print OS..."


void print_title();
void strip_quotes(char *str);
const char *get_username();
void print_uptime();
void print_kernel_version();
void print_os_info();
void print_sysinfo_version();
char* get_hostname();

#endif