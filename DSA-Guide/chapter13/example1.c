#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50

struct Person;

typedef struct FriendNode {
    struct Person* person;
    struct FriendNode* next;
} FriendNode;

typedef struct Person {
    char name[NAME_LEN];
    FriendNode* friends;
    int visited;
} Person;

Person* create_person(const char* name) {
    Person* new_person = (Person*)malloc(sizeof(Person));
    strncpy(new_person->name, name, NAME_LEN);
    new_person->friends = NULL;
    new_person->visited = 0;
    return new_person;
}

void add_friend(Person* p, Person* friend) {
    FriendNode* new_friend = (FriendNode*)malloc(sizeof(FriendNode));
    new_friend->person = friend;
    new_friend->next = p->friends;
    p->friends = new_friend;
}

typedef struct QueueNode {
    Person* person;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Person* person) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->person = person;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Person* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Person* person = temp->person;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return person;
}

int is_queue_empty(Queue* q) {
    return q->front == NULL;
}

typedef struct NodeList {
    Person* person;
    struct NodeList* next;
} NodeList;

void add_to_reset_list(NodeList** head, Person* person) {
    NodeList* node = (NodeList*)malloc(sizeof(NodeList));
    node->person = person;
    node->next = *head;
    *head = node;
}

void display_network(Person* start) {
    Queue* queue = create_queue();
    NodeList* to_reset = NULL;

    enqueue(queue, start);
    start->visited = 1;
    add_to_reset_list(&to_reset, start);

    while (!is_queue_empty(queue)) {
        Person* current = dequeue(queue);
        printf("%s\n", current->name);

        FriendNode* f = current->friends;
        while (f != NULL) {
            if (!f->person->visited) {
                enqueue(queue, f->person);
                f->person->visited = 1;
                add_to_reset_list(&to_reset, f->person);
            }
            f = f->next;
        }
    }

    NodeList* temp = to_reset;
    while (temp != NULL) {
        temp->person->visited = 0;
        NodeList* old = temp;
        temp = temp->next;
        free(old);
    }

    free(queue);
}

int main() {
    Person* alice = create_person("Alice");
    Person* bob = create_person("Bob");
    Person* charlie = create_person("Charlie");
    Person* dave = create_person("Dave");

    add_friend(alice, bob);
    add_friend(bob, charlie);
    add_friend(charlie, dave);
    add_friend(dave, alice);

    printf("Network from Alice:\n");
    display_network(alice);
    free(alice);
    free(bob);
    free(charlie);
    free(dave);

    return 0;
}
