#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"


int main(int argc, char **argv){

    FILE *fp;
    char ch;

    CharStack charStack;
    charStack.stackLength = 0;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Unable to open file");
        return -1;
    }

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