#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void find_directories(const char *directory) {
    struct dirent *entry;
    DIR *dir = opendir(directory);

    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
        struct stat info;
        if (stat(path, &info) == 0 && S_ISDIR(info.st_mode)) {
            printf("%s\n", path);
            find_directories(path);
        }
    }

    closedir(dir);
}

int main() {
    find_directories(".");
    return 0;
}
