#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// Define a stack structure
struct Stack {
    char data[STACK_SIZE];
    int top;
};

// Function to push a character onto the stack
void push(struct Stack *stack, char c) {
    if (stack->top < STACK_SIZE - 1) {
        stack->data[++stack->top] = c;
    } else {
        printf("Stack is full. Cannot push character: %c\n", c);
    }
}

// Function to pop a character from the stack
char pop(struct Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        return '\0'; // Return null character to indicate an empty stack
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s test.txt\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct Stack stack;
    stack.top = -1; // Initialize the top of the stack

    char c;
    while ((c = fgetc(file)) != EOF) {
        push(&stack, c);
    }

    fclose(file);

    printf("Contents of the file in reverse order:\n");
    while (stack.top >= 0) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}