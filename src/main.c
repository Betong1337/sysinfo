/******************************************************************************
 *  main.c
 *
 *  Author: Betong1337 (Jakob Asp)
 *  Created: 2026-01-02
 *  Description: Main entry point for the project.
 *
 *  License: MIT License
 *  See LICENSE.md for full license text.
 *****************************************************************************/
#include <main.h>
#include <cpu.h>
#include <memory.h>
#include <sysinfo.h>

void print_all() {
    print_title();
    print_os_info();
    print_kernel_version();
    print_cpu_model();
    print_mem_total();
    print_swap();
    print_uptime();
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_all();
        return 1;
    }

    if (strcmp(argv[1], CPU_ARGV_CMP) == 0) {
        print_cpu_model();
    } else if (strcmp(argv[1], MEM_ARGV_CMP) == 0) {
        print_mem_total();
    } else if (strcmp(argv[1], SWAP_ARGV_CMP) == 0) {
        print_swap();
    } else if (strcmp(argv[1], ALL_ARGV_CMP) == 0) {
        print_all();
    } else if (strcmp(argv[1], UPTIME_ARGV_CMP1) == 0 || strcmp(argv[1], UPTIME_ARGV_CMP2) == 0) {
        print_uptime();
    } else if (strcmp(argv[1], SYSINFO_VERSION_ARGV_CMP1) == 0 || strcmp(argv[1], SYSINFO_VERSION_ARGV_CMP2) == 0) {
        print_sysinfo_version();
    } else if (strcmp(argv[1], OS_ARGV_CMP) == 0) {
        print_os_info();
    } else if (strcmp(argv[1], HELP_ARGV_CMP) == 0) {
        printf("%s", USAGE_MSG);
    } else if (strcmp(argv[1], KERNEL_VERSION_ARGV_CMP) == 0) {
        print_kernel_version();
    } else {
        printf("%s", USAGE_MSG);
    }
    
    return 0;
}
