#include <stdio.h>
#include <string.h>

#define SIZE 10
#define MAX_DOC_LEN 100

char queue[SIZE][MAX_DOC_LEN];
int front = 0;
int rear = 0;

void queue_print_job(char* document) {
    if (rear < SIZE) {
        strcpy(queue[rear], document);
        rear++;
        printf("Queued: %s\n", document);
    } else {
        printf("Queue is full. Cannot add: %s\n", document);
    }
}
void print(char* document) {
    printf("Printing: %s\n", document);
}

void run() {
    while (front < rear) {
        print(queue[front]);
        front++;
    }
}



int main() {
    queue_print_job("First Document");
    queue_print_job("Second Document");
    queue_print_job("Third Document");

    printf("\n--- Running Printer ---\n");
    run();

    return 0;
}
