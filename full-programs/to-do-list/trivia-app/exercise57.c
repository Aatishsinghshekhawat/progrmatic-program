#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 4
#define MAX_LINE 256

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][50];
    int correctIndex;
} Question;

int loadQuestions(Question questions[]) {
    FILE *file = fopen("questions.txt", "r");
    if (!file) {
        printf("Error: Could not open questions.txt\n");
        return 0;
    }

    int count = 0;
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file) && count < MAX_QUESTIONS) {
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%d",
               questions[count].question,
               questions[count].choices[0],
               questions[count].choices[1],
               questions[count].choices[2],
               questions[count].choices[3],
               &questions[count].correctIndex);
        questions[count].correctIndex--;  // Convert 1-based to 0-based index
        count++;
    }
    fclose(file);
    return count;
}

void playGame(Question questions[], int totalQuestions) {
    int score = 0;
    srand(time(NULL));

    while (1) {
        int index = rand() % totalQuestions;

        printf("\n%s\n", questions[index].question);
        for (int i = 0; i < MAX_CHOICES; i++) {
            printf("%d. %s\n", i + 1, questions[index].choices[i]);
        }

        int userChoice;
        printf("Your answer (1-4): ");
        scanf("%d", &userChoice);

        if (userChoice - 1 == questions[index].correctIndex) {
            printf(" Correct!\n");
            score++;
        } else {
            printf(" Wrong! Game Over.\nFinal Score: %d\n", score);
            break;
        }
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    int totalQuestions = loadQuestions(questions);

    if (totalQuestions == 0) {
        printf("No questions available.\n");
        return 1;
    }

    playGame(questions, totalQuestions);
    return 0;
}
