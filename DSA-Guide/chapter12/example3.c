#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->leftChild = insert(root->leftChild, value);
    } else if (value > root->value) {
        root->rightChild = insert(root->rightChild, value);
    }

    return root;
}

struct Node* lift(struct Node* node, struct Node* nodeToDelete) {
    if (node->leftChild != NULL) {
        node->leftChild = lift(node->leftChild, nodeToDelete);
        return node;
    } else {
        nodeToDelete->value = node->value;
        return node->rightChild;
    }
}

struct Node* deleteNode(struct Node* root, int valueToDelete) {
    if (root == NULL) {
        return NULL;
    }

    if (valueToDelete < root->value) {
        root->leftChild = deleteNode(root->leftChild, valueToDelete);
    } else if (valueToDelete > root->value) {
        root->rightChild = deleteNode(root->rightChild, valueToDelete);
    } else {
        if (root->leftChild == NULL) {
            return root->rightChild;
        } else if (root->rightChild == NULL) {
            return root->leftChild;
        } else {
            root->rightChild = lift(root->rightChild, root);
        }
    }

    return root;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->leftChild);
        printf("%d ", root->value);
        inorder(root->rightChild);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder before deletion: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
