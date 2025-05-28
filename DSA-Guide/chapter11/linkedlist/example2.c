#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int search(Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return 1;
        head = head->next;
    }
    return 0;
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 5;
    head->next = malloc(sizeof(Node));
    head->next->data = 15;
    head->next->next = NULL;

    int result = search(head, 15);
    printf(result ? "Found\n" : "Not found\n");
    return 0;
}
