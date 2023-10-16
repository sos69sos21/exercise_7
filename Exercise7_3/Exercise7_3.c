#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

// Create struct stack of integers with a max size (Max_stack_size and it
// keeps track of the length of the stack in the stackLength variable
typedef struct{
    int stackLength;
    int stackElements[MAX_STACK_SIZE];
} CharStack;

int Push(int c, CharStack *charStack);
int Pop(CharStack *charStack);

int main(int argc, char **argv){

    FILE *fp;
    char ch;

    CharStack charStack;
    charStack.stackLength = 0;

    // open file using CLI command
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Unable to open file");
        return -1;
    }

    // read characters from a file then pushes them onto a stack
    // then pops and prints in reverse order
    while ((ch = fgetc(fp)) != EOF)
    {
        Push(ch, &charStack);
    }

    int stackLength = charStack.stackLength;
    for(int i = 0; i < stackLength; i++){
        printf("%c", Pop(&charStack));
    }

    printf("\n");
    fclose(fp);
    return 0;
}

// push function to add elements to the stack
// checks for space in the stack
// then adds element and updates length
// error of -1 if already full
int Push(int c, CharStack *charStack){
    if(charStack->stackLength < MAX_STACK_SIZE){
        charStack->stackElements[charStack->stackLength] = c;
        charStack->stackLength++;
        return 0;
    }
    return -1;
}

// removes top element from stack
// check to see if stack is empty
// updates stack length
// if empty, it returns a -1
int Pop(CharStack *charStack){
    if(charStack->stackLength < 1){
        return -1;
    }
    int element = charStack->stackElements[charStack->stackLength-1];
    charStack->stackElements[charStack->stackLength-1] = 0;
    charStack->stackLength--;
    return element;
}