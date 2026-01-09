#include <gpu.h>

void print_gpus() {
    FILE *fp;
    char path[1035];

    fp = popen(GPU_COMMAND, "r");
    if (!fp) return;

    const char *sep = "controller:";
    char *pos; 

    int gpu_count = 1;

    while (fgets(path, sizeof(path), fp) != NULL) {
        pos = strstr(path, sep);
        char *GPU = pos + strlen(sep);
        printf(GPU_MSG, HEADER, "GPU ", gpu_count,":", RESET, GPU);
        gpu_count++;
    }

    pclose(fp);
}