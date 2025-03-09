#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 256
#define FILE_NAME "todo.txt"

// Function to add a task to the file
void addTask() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char task[TASK_LENGTH];
    while (1) {
        printf("Enter a task (or press ENTER to stop): ");
        fgets(task, TASK_LENGTH, stdin);

        if (task[0] == '\n') // Stop if blank line is entered
            break;

        fprintf(file, "%s", task); // Write task to file
    }

    fclose(file);
}

// Function to display all tasks
void showTasks() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No tasks found.\n");
        return;
    }

    char task[TASK_LENGTH];
    int taskNumber = 1;
    printf("\nYour To-Do List:\n");
    while (fgets(task, TASK_LENGTH, file)) {
        printf("%d. %s", taskNumber++, task);
    }

    fclose(file);
}

// Function to remove a task
void removeTask() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No tasks found.\n");
        return;
    }

    char tasks[MAX_TASKS][TASK_LENGTH];
    int count = 0;

    while (fgets(tasks[count], TASK_LENGTH, file) && count < MAX_TASKS) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No tasks to remove.\n");
        return;
    }

    int taskToRemove;
    printf("Enter the task number to remove: ");
    scanf("%d", &taskToRemove);
    getchar(); // Consume newline

    if (taskToRemove < 1 || taskToRemove > count) {
        printf("Invalid task number.\n");
        return;
    }

    file = fopen(FILE_NAME, "w");
    for (int i = 0; i < count; i++) {
        if (i != taskToRemove - 1) {
            fprintf(file, "%s", tasks[i]);
        }
    }
    fclose(file);

    printf("Task removed successfully!\n");
}

// Main menu
int main() {
    int choice;
    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Show Tasks\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: removeTask(); break;
            case 4: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
