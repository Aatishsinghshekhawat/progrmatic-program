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

void insert(int value, Node* node) {
    if (value < node->value) {
        if (node->leftChild == NULL) {
            node->leftChild = create_node(value);
        } else {
            insert(value, node->leftChild);
        }
    } else if (value > node->value) {
        if (node->rightChild == NULL) {
            node->rightChild = create_node(value);
        } else {
            insert(value, node->rightChild);
        }
    }
   
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->leftChild);
        printf("%d ", root->value);
        inorder(root->rightChild);
    }
}

int main() {
    Node* root = create_node(50);
    insert(30, root);
    insert(70, root);
    insert(20, root);
    insert(40, root);
    insert(60, root);
    insert(80, root);

    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
