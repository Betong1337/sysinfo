#include <cpu.h>

void print_cpu_model() {
    FILE *f = fopen(CPUINFO_PATH, "r");
    if (!f) {
        printf(CPU_ERROR_MSG, HEADER, CPU_PREFIX, RESET, CPU_ERROR);
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), f)) {
        if (strncmp(CPU_MODEL_NAME, line, 10) == 0) {
            printf(CPU_MSG, HEADER, CPU_PREFIX, RESET, strchr(line, ':') + 2);
            break;
        }
    }
    fclose(f);
}