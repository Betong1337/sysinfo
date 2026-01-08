#include <sysinfo.h>

void print_title() {
    char *hostname = get_hostname();
    const char *username = get_username();
    if (!hostname) return;
    printf(PRINT_TITLE_MSG, HEADER, username, hostname, RESET);
}

void strip_quotes(char *str) {
    size_t len = strlen(str);

    if (len >= 2 && str[0] == '"' && str[len - 1] == '"') {
        str[len - 1] = '\0'; 
        memmove(str, str + 1, len);
    }
}

const char *get_username() {
    struct passwd *pw = getpwuid(getuid());
    return pw ? pw->pw_name : NULL;
}

void print_uptime() {
    FILE *f = fopen(UPTIME_PATH, "r");
    if (!f) return;

    char line[256];
    if (!fgets(line, sizeof line, f)) {
        fclose(f);
        return;
    }

    float hours = atof(strtok(line, " ")) / 3600.0;
    fclose(f);

    if (hours < 24) {
        printf(UPTIME_MSG1, HEADER, UPTIME_PREFIX, RESET,(int) hours);
        return;
    }

    int days = hours / 24;
    hours -= days * 24;
    int mins = (int)((hours - (int)hours) * 60);
    printf(UPTIME_MSG2, HEADER, UPTIME_PREFIX, RESET, days, (int) hours, mins);
}

void print_kernel_version() {
    FILE *f = fopen(KERNEL_PATH, "r");
    if (!f) return;

    char line[256];
    char *kernel_version = fgets(line, sizeof(line), f);
    if (!kernel_version) {
        fclose(f);
        return;
    }

    kernel_version = strtok(kernel_version, "(");
    printf(KERNEL_MSG, HEADER, KERNEL_VER_PREFIX, RESET, kernel_version);
    fclose(f);
}

void print_os_info() {
    FILE *f = fopen(OS_PATH, "r");
    if (!f) return;

    char line[256];

    char *key;
    char *value;
    char os_type[64];
    char os_version[64];

    while (fgets(line, sizeof(line), f)) {
        key = strtok(line, "=");    
        value = strtok(NULL, "=");  

        if (strncmp(OS_NAME_CMP, key, 4) == 0) {
            strcpy(os_type, value);
        }
        if (strncmp(OS_VERSION_CMP, key, 6) == 0) {
            strcpy(os_version, value);
            os_version[strcspn(os_version, "\n")] = '\0';
            os_type[strcspn(os_type, "\n")] = '\0';
            strip_quotes(os_version);
            strip_quotes(os_type);              
            printf(OS_MSG, HEADER, OS_PREFIX, RESET, os_type, os_version);
            break;
        }
    }
    fclose(f);
}

void print_sysinfo_version() {
    printf(SYSINFO_VERSION_MSG);
}

char* get_hostname() {
    FILE *f = fopen(HOSTNAME_PATH, "r");
    if (!f) return NULL;

    static char line[256];

    if (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = 0;
        fclose(f);
        return line;
    }
    fclose(f);
    return NULL;
}

