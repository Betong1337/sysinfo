#include <memory.h>

char* trim_leading_spaces(char *str) {
    while (*str == ' ' || *str == '\t') {
        str++;
    }
    return str;
}

char* get_memory_info(char *option) {
    int option_len;

    if (strcmp(option, "MemTotal") == 0) {
        option_len = 7;
    } else if (strcmp(option, "MemAvailable") == 0) {
        option_len = 6;
    } else if (strcmp(option, "SwapTotal") == 0) {
        option_len = 8;
    } else if (strcmp(option, "SwapFree") == 0) {
        option_len = 7;
    } else if (strcmp(option, "SwapCached") == 0) {
        option_len = 9;
    }

    FILE *mem_file = fopen(MEMINFO_PATH, "r");
    char line[256];
    float gb_float;
    if (mem_file != NULL) {
        while (fgets(line, sizeof(line), mem_file)) { 
            if (strncmp(option, line, option_len) == 0) {
                char *value = strchr(line, ':') + 2;
                value = trim_leading_spaces(value);
                gb_float = atof(value) / 1048576.0;
                char *gb_str = malloc(32);
                if (gb_str != NULL) {
                    sprintf(gb_str, "%.2f", gb_float);
                }
                fclose(mem_file);
                return gb_str;
            }
        }
        fclose(mem_file);
    }
    return NULL;
}

void print_mem_total() {
    char *gb_total = get_memory_info("MemTotal");
    char *gb_available = get_memory_info("MemAvailable");

    float total = atof(gb_total);
    float available = atof(gb_available);

    float used_mem = total - available;

    printf("\033[1;34m%s\033[0m", "Memory: ");
    printf("%.2f GB / %s GB\n", used_mem, gb_total);
    free(gb_total);
    free(gb_available);
}

void print_swap() {
    char *swap_total = get_memory_info("SwapTotal");
    char *swap_free = get_memory_info("SwapFree");
    char *swap_cached = get_memory_info("SwapCached");

    float swap_total_f = atof(swap_total);
    float swap_free_f = atof(swap_free);
    float swap_cached_f = atof(swap_cached);

    float swap_used = swap_total_f - swap_free_f - swap_cached_f;

    printf("\033[1;34m%s\033[0m", "Swap: ");
    printf("%.2f GB / %.2f GB\n", swap_used, swap_total_f);
}