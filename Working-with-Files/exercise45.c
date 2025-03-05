#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceWordInFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    if (!in) {
        printf("Error: Could not open input file.\n");
        return;
    }

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        printf("Error: Could not open output file.\n");
        fclose(in);
        return;
    }

    char word[50];
    while (fscanf(in, "%s", word) != EOF) {
        if (strcmp(word, "utilize") == 0) {
            fprintf(out, "use ");
        } else {
            fprintf(out, "%s ", word);
        }
    }

    fclose(in);
    fclose(out);
    printf("Word replacement completed! Check %s\n", outputFile);
}

int main() {
    char inputFile[50], outputFile[50];

    printf("Enter the input file name: ");
    scanf("%s", inputFile);
    printf("Enter the output file name: ");
    scanf("%s", outputFile);

    replaceWordInFile(inputFile, outputFile);

    return 0;
}
