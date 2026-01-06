#include <cpu.h>

void print_cpu_model() {
    FILE *cpu_file = fopen(CPUINFO_PATH, "r");
    char line[256];
    if (cpu_file != NULL) {
        while (fgets(line, sizeof(line), cpu_file)) {
            if (strncmp("model name", line, 10) == 0) {
                printf("\033[1;34m%s\033[0m", "CPU: ");
                printf("%s", strchr(line, ':') + 2);
                break;
            }
        }
    fclose(cpu_file);

    }

}