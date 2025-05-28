#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return create_node(value);

    if (value < root->value)
        root->leftChild = insert(root->leftChild, value);
    else if (value > root->value)
        root->rightChild = insert(root->rightChild, value);

    return root;
}

Node* search(int value, Node* node) {
    if (node == NULL || node->value == value)
        return node;

    if (value < node->value)
        return search(value, node->leftChild);
    else
        return search(value, node->rightChild);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->leftChild);
        printf("%d ", root->value);
        inorder(root->rightChild);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("In-order Traversal of Tree: ");
    inorder(root);
    printf("\n");

    int targets[] = {40, 25, 80, 90};
    for (int i = 0; i < 4; i++) {
        int val = targets[i];
        Node* result = search(val, root);
        if (result != NULL)
            printf("Found %d\n", val);
        else
            printf("Value %d not found\n", val);
    }

    return 0;
}
