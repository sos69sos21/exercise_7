#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100

typedef struct{
    int stackLength;
    int stackElements[MAX_STACK_SIZE];
} CharStack;

int Push(int c, CharStack *charStack);
int Pop(CharStack *charStack);

#endif