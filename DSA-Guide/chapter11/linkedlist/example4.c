#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void delete(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; 
    if (prev == NULL) {
        *head = temp->next; 
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 10;
    head->next = malloc(sizeof(Node));
    head->next->data = 20;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    delete(&head, 20);
    print(head);
    return 0;
}
