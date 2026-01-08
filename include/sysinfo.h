//Everthing that is not cpu or memory should be here
#ifndef SYSINFO_H
#define SYSINFO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>
#include <defines.h>

#define OS_PATH          "/etc/os-release"
#define KERNEL_PATH      "/proc/version"
#define HOSTNAME_PATH    "/proc/sys/kernel/hostname"
#define UPTIME_PATH      "/proc/uptime"

void print_title();
void strip_quotes(char *str);
const char *get_username();
void print_uptime();
void print_kernel_version();
void print_os_info();
void print_sysinfo_version();
char* get_hostname();

#endif