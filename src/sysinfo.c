#include <sysinfo.h>

void print_title() {
    const char* user = get_username();
    char* hostname = get_hostname();
    if (hostname != NULL) {
         printf("\033[1;34m=== %s@%s ===\033[0m\n", user, hostname);
    }
}

const char *get_username() {
    struct passwd *pw = getpwuid(getuid());
    return pw ? pw->pw_name : NULL;
}


void print_uptime() {
    FILE *uptime_file = fopen(UPTIME_PATH, "r");
    char line[256];

    if (uptime_file != NULL) {
        while (fgets(line, sizeof(line), uptime_file)) {
            char* uptime_seconds = strtok(line, " ");
            float uptime_hours = (atof(uptime_seconds) / 60) / 60;
            printf("\033[1;34m%s\033[0m", "Uptime: ");
            printf("%.2f hours\n", uptime_hours);
            break;
        }
    }
    fclose(uptime_file);
}

void print_kernel_version() {
    FILE *kernel_ver_file = fopen(KERNEL_PATH,"r");
    char line[256];
    char *kernel_version = fgets(line, sizeof(line), kernel_ver_file);
    kernel_version = strtok(kernel_version, "(");
    printf("\033[1;34m%s\033[0m", "Kernel Version: ");
    printf("%s\n", kernel_version);
    fclose(kernel_ver_file);
}

void print_os_type() {
    FILE *os_type_file = fopen(OS_PATH, "r");
    char line[256];
    char *key;
    char *value;

    if (os_type_file != NULL) {
        while (fgets(line, sizeof(line), os_type_file)) {
            key = strtok(line, "=");    
            value = strtok(NULL, "=");  

            if (strncmp("NAME", key, 4) == 0) {
                printf("\033[1;34m%s\033[0m", "OS: ");
                printf("%s", value);
            }
        }
    fclose(os_type_file);
    }
}

char* get_hostname() {
    static char line[256];
    FILE *hostname_file = fopen(HOSTNAME_PATH, "r");
    if (hostname_file != NULL) {
        if (fgets(line, sizeof(line), hostname_file)) {
            line[strcspn(line, "\n")] = 0;
            fclose(hostname_file);
            return line;
        }
        fclose(hostname_file);
    }
    return NULL;
}
