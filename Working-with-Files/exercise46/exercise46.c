#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char word[20];
    int count;
} WordFreq;

void addOrUpdateWord(WordFreq words[], int *size, char *newWord) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(words[i].word, newWord) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[*size].word, newWord);
    words[*size].count = 1;
    (*size)++;
}

void printHistogram(WordFreq words[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: ", words[i].word);
        for (int j = 0; j < words[i].count; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("words.txt", "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    WordFreq words[MAX_WORDS];
    int wordCount = 0;
    char tempWord[20];

    while (fscanf(file, "%s", tempWord) != EOF) {
        addOrUpdateWord(words, &wordCount, tempWord);
    }

    fclose(file);

    printf("Word Frequency Histogram:\n");
    printHistogram(words, wordCount);

    return 0;
}
