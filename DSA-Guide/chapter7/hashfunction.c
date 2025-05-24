#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 20

typedef struct Node {
    char key[20];
    char value[20];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int letter_to_number(char c) {
    return toupper(c) - 'A' + 1;
}

int hash(char* key) {
    int product = 1;
    for (int i = 0; key[i] != '\0'; i++) {
        if (isalpha(key[i]))
            product *= letter_to_number(key[i]);
    }
    return product % TABLE_SIZE;
}

void insert(char* key, char* value) {
    int index = hash(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

char* lookup(char* key) {
    int index = hash(key);
    Node* current = hashTable[index];

    while (current) {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }

    return "Not found";
}


int main() {
    insert("bad", "evil");
    insert("cab", "taxi");
    insert("ace", "star");

    printf("Synonym for 'bad': %s\n", lookup("bad"));
    printf("Synonym for 'cab': %s\n", lookup("cab"));
    printf("Synonym for 'ace': %s\n", lookup("ace"));

    return 0;
}
