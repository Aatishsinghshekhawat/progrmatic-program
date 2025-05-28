#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
    Node* first_node;
    Node* last_node;
} DoublyLinkedList;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert_at_end(DoublyLinkedList* list, int value) {
    Node* new_node = create_node(value);

    if (list->first_node == NULL) {
        list->first_node = new_node;
        list->last_node = new_node;
    } else {
        new_node->prev = list->last_node;
        list->last_node->next = new_node;
        list->last_node = new_node;
    }
}

void print_forward(DoublyLinkedList* list) {
    Node* current = list->first_node;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    DoublyLinkedList list = {NULL, NULL};

    insert_at_end(&list, 10);
    insert_at_end(&list, 20);
    insert_at_end(&list, 30);

    print_forward(&list);

    return 0;
}
