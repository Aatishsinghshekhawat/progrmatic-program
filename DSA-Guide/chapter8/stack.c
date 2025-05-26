#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

char stack[MAX_LEN];
int top = -1;

void push(char c) {
    if (top < MAX_LEN - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0'; 
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int is_opening(char c) {
    return c == '(' || c == '[' || c == '{';
}

int is_closing(char c) {
    return c == ')' || c == ']' || c == '}';
}

char matching_opening(char c) {
    switch (c) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return '\0';
    }
}

void lint(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (is_opening(c)) {
            push(c);
        } else if (is_closing(c)) {
            if (peek() == matching_opening(c)) {
                pop();
            } else {
                printf("Incorrect closing brace: at index %d\n", i);
                return;
            }
        }
    }

    if (top >= 0) {
        printf(" does not have a closing brace\n", peek());
    } else {
        printf("All braces are correct.\n");
    }
}

int main() {
    // Correct line
    lint("( var x = { y: [1, 2, 3] } )");

    // Incorrect closing brace
    lint("( var x = { y: [1, 2, 3] ) }");

    //  Missing closing brace
    lint("( var x = { y: [1, 2, 3] }");

    return 0;
}
