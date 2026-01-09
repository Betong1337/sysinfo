#include <gpu.h>

void print_gpus() {
    FILE *fp;
    char path[1035];

    fp = popen(GPU_COMMAND, "r");
    if (!fp) return;

    const char *sep = "controller:";
    char *pos;

    while (fgets(path, sizeof(path), fp) != NULL) {
        pos = strstr(path, sep);
        char *first = path;
        char *GPU = pos + strlen(sep);
        printf(GPU_MSG, HEADER, "GPU:", RESET, GPU);
    }

    pclose(fp);
}