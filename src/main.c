#include <main.h>
#include <cpu.h>
#include <memory.h>
#include <sysinfo.h>

void print_all() {
    print_title();
    print_os_type();
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

    if (strcmp(argv[1], "--cpu") == 0) {
        print_cpu_model();
    } else if (strcmp(argv[1], "--mem") == 0) {
        print_mem_total();
    } else if (strcmp(argv[1], "--swap") == 0) {
        print_swap();
    } else if (strcmp(argv[1], "--all") == 0) {
        print_all();
    } else if (strcmp(argv[1], "--uptime") == 0 || strcmp(argv[1], "--up") == 0) {
        print_uptime();
    } else if (strcmp(argv[1], "--version" ) == 0 || strcmp(argv[1], "--ver") == 0) {
        print_kernel_version();
    } else if (strcmp(argv[1], "--os") == 0) {
        print_os_type();
    } else if (strcmp(argv[1], "--help") == 0) {
        printf("%s", USAGE_MSG);
    } else {
        printf("%s", USAGE_MSG);
    }
    
    return 0;
}
