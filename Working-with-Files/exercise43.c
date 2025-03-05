#include <stdio.h>
#include <stdlib.h>

void createFolder(const char *name) {
    char command[100];
    sprintf(command, "mkdir -p %s", name);
    system(command);
}

void createFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s", content);
        fclose(file);
    }
}

int main() {
    char siteName[50], author[50], path[100];
    char createJs, createCss;

    printf("Site name: ");
    scanf("%s", siteName);
    printf("Author: ");
    scanf("%s", author);

    sprintf(path, "./%s", siteName);
    createFolder(path);

    sprintf(path, "./%s/index.html", siteName);
    createFile(path, "<html><head></head><body></body></html>");

    printf("Do you want a JavaScript folder? (y/n): ");
    scanf(" %c", &createJs);
    if (createJs == 'y') {
        sprintf(path, "./%s/js", siteName);
        createFolder(path);
    }

    printf("Do you want a CSS folder? (y/n): ");
    scanf(" %c", &createCss);
    if (createCss == 'y') {
        sprintf(path, "./%s/css", siteName);
        createFolder(path);
    }

    printf("Website structure created.\n");
    return 0;
}
