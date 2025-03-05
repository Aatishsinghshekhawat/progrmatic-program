#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int numResponses, index;

    char *responses[] = {"Yes", "No", "Maybe", "Ask again later"};
    int numResponses = sizeof(responses) / sizeof(responses[0]);

    char question[100];
    printf("What's your question? ");
    fgets(question, sizeof(question), stdin);

    srand(time(0));
    index = rand() % numResponses;

    printf("%s\n", responses[index]);
    return 0;
}
