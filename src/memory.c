#include <memory.h>

char* trim_leading_spaces(char *str) {
    while (*str == ' ' || *str == '\t') {
        str++;
    }
    return str;
}

char* get_memory_info(char *option) {
    int option_len;

    if (strcmp(option, MEM_TOTAL_CMP) == 0) {
        option_len = 7;
    } else if (strcmp(option, MEM_AVAILABLE_CMP) == 0) {
        option_len = 6;
    } else if (strcmp(option, SWAP_TOTAL_CMP) == 0) {
        option_len = 8;
    } else if (strcmp(option, SWAP_FREE_CMP) == 0) {
        option_len = 7;
    } else if (strcmp(option, SWAP_CACHED_CMP) == 0) {
        option_len = 9;
    }

    FILE *f = fopen(MEMINFO_PATH, "r");
    char line[256];
    float gb_float;
    if (!f) return NULL;

    while (fgets(line, sizeof(line), f)) { 
        if (strncmp(option, line, option_len) == 0) {
            char *value = strchr(line, ':') + 2;
            value = trim_leading_spaces(value);
            gb_float = atof(value) / 1048576.0;
            char *gb_str = malloc(32);
            if (gb_str != NULL) {
                sprintf(gb_str, "%.2f", gb_float);
            }
            fclose(f);
            return gb_str;
        }
    }
    fclose(f);
    return NULL;
}

char *get_percentage_color(int used_percent) {
    char *procent_color;
    if (used_percent < 50) {
        procent_color = GREEN;
    } else if (used_percent > 49 && used_percent < 80) {
        procent_color = YELLOW;
    } else {
        procent_color = RED;
    }
    return procent_color;
}

void print_mem_total() {
    char *gb_total = get_memory_info(MEM_TOTAL_CMP);
    char *gb_available = get_memory_info(MEM_AVAILABLE_CMP);

    float total = atof(gb_total);
    float available = atof(gb_available);

    float used_mem = total - available;

    int used_percent = (used_mem / total) * 100;
    char *procent_color = get_percentage_color(used_percent);

    printf(MEM_MSG, HEADER, MEM_PREFIX, RESET, used_mem, total, procent_color, used_percent, RESET);
    free(gb_total);
    free(gb_available);
}

void print_swap() {
    char *swap_total = get_memory_info(SWAP_TOTAL_CMP);
    char *swap_free = get_memory_info(SWAP_FREE_CMP);
    char *swap_cached = get_memory_info(SWAP_CACHED_CMP);

    float swap_total_f = atof(swap_total);
    float swap_free_f = atof(swap_free);
    float swap_cached_f = atof(swap_cached);
    free(swap_total);
    free(swap_free);
    free(swap_cached);

    float swap_used = swap_total_f - swap_free_f - swap_cached_f;
    int used_percent = (swap_used / swap_total_f) * 100;
    char *procent_color = get_percentage_color(used_percent);

    printf(MEM_MSG, HEADER, SWAP_PREFIX, RESET, swap_used, swap_total_f, procent_color, used_percent, RESET);
}