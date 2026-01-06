#include <memory.h>

char* trim_leading_spaces(char *str) {
    while (*str == ' ' || *str == '\t') {
        str++;
    }
    return str;
}

void print_mem_total() {
    FILE *mem_file = fopen(MEMINFO_PATH, "r");
    char line[256];
    static char gb_str[32];
    float gb_float;
    if (mem_file != NULL) {
        while (fgets(line, sizeof(line), mem_file)) {
            if (strncmp("MemTotal", line, 8) == 0) {
                char *value = strchr(line, ':') + 2;
                value = trim_leading_spaces(value);
                gb_float = atof(value) / 1048576.0; 
                sprintf(gb_str, "%.2f", gb_float);
            }
            if (strncmp("MemAvailable", line, 11) == 0) {
                char *memAvailable = strchr(line, ':') + 2;
                memAvailable = trim_leading_spaces(memAvailable);
                static char used_mem_str[32];
                float mem_avail_float = atof(memAvailable) / 1048576.0; 
                float used_mem_float = gb_float - mem_avail_float;
                sprintf(used_mem_str, "%.2f", used_mem_float);
                printf("\033[1;34m%s\033[0m", "Memory: ");
                printf("%s GB / %s GB\n", used_mem_str, gb_str);
                break;
            }
        }
        fclose(mem_file);
    }


}