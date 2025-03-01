#include <stdio.h>

int main() {
    char quote[100], author[50];
    printf("What is the quote? ");
    scanf(" %[^\n]", quote);
    printf("Who said it? ");
    scanf(" %[^\n]", author);
    printf("%s says, \"%s\"\n", author, quote);
    return 0;
}

