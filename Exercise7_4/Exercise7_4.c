#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a structure to hold word count information
struct WordCount{
    char word[50];
    int count;
    struct WordCount* left;
    struct WordCount* right;
};

// function to insert a word into the binary search treee
struct WordCount* insert(struct WordCount* root, const char* word){
    if(root == NULL){
        // Create a new node if the tree is empty
        struct WordCount* newNode = (struct WordCount*)malloc(sizeof(struct WordCount));
            if(root == NULL){
                struct WordCount *newNode = (struct WordCount*)malloc(sizeof(struct WordCount));
                strcpy(newNode->word, word);
                newNode->count = 1;
                newNode->left = newNode->right = NULL;
                return newNode;
            }
    }

    int cmp = strcmp(word, root->word);
    if(cmp < 0){
        root->left = insert(root->left, word); // insert into the left subtree
    }
    else if(cmp > 0){
        root->right = insert(root->right, word); // insert into the right subtree
    }
    else{
        root->count++;  //if word already exist then increment count
    }
    return root;
}

// function to display all words and their counts
// traversal to print words and counts
void displayAllWords(struct WordCount *root){
    if(root != NULL){
        displayAllWords(root->left);
        printf("%s: %d\n", root->word, root->count);
        displayAllWords(root->right);
    }
}

// function to search for a specific word
int searchWord(struct WordCount *root, const char* word){
    if(root == NULL){  // word not found
        return 0;
    }

    int cmp = strcmp(word, root->word);
    if(cmp < 0){
        return searchWord(root->left, word); // search in left subtree
    }
    else if(cmp > 0){
        return searchWord(root->right, word); // search in the right subtree
    }
    else{
        return root->count; // word found, return its count
    }
}

// function to free the memory used by the binary search tree
void freeTree(struct WordCount *root){
    if(root != NULL){
        // traversal to free memory
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    FILE *fp = fopen("moby.txt", "r");

    if(fp == NULL){
        perror("File Opening Error");
        exit(1);
    }

    struct WordCount *root = NULL;
    char word[50];

    // read words from Moby and insert them into the binary search tree
    while(fscanf(fp, "%s", word) == 1){
        root = insert(root, word);
    }

    fclose(fp);
    int choice;
    char SearchWordInput[50];

    do{
        // display menu options
        printf("Options Menu:\n");
        printf("   1. List Words\n");
        printf("   2. Enter a Word to Search\n");
        printf("   3. Quit\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                // List all words and their counts
                printf("Words and their counts:\n");
                displayAllWords(root);
                break;
            case 2:
                // search for a specific word
                printf("Enter the word to search: ");
                scanf("%s", SearchWordInput);
                printf("'%s' occurred %d times in the file.\n", SearchWordInput, searchWord(root, SearchWordInput));
                break;
            case 3:
                // quit the program
                break;
            default:
                printf("\nInvalid Choice.  Select Between 1-3 Only, Thanks!!\n");
        }

    }while(choice != 3);

    freeTree(root);

    return 0;
}