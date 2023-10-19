#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int Push(int c, CharStack *charStack){
    if(charStack->stackLength < MAX_STACK_SIZE){
        charStack->stackElements[charStack->stackLength] = c;
        charStack->stackLength++;
        return 0;
    }
    return -1;
}

int Pop(CharStack *charStack){
    if(charStack->stackLength < 1){
        return -1;
    }
    int element = charStack->stackElements[charStack->stackLength-1];
    charStack->stackElements[charStack->stackLength-1] = 0;
    charStack->stackLength--;
    return element;
}
