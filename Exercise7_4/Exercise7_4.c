#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD 50

// function to insert a word into the binary search tree
struct StringCount* insert(struct StringCount* root, const char* word);

// function to display all words and their counts
// traversal to print words and counts
void displayAllWords(struct StringCount *root);

// function to search for a specific word
int searchWord(struct StringCount *root, const char* word);

// function to free the memory used by the binary search tree
void deleteTree(struct StringCount *root);

// define a structure to hold word count information
struct StringCount{
    char word[MAX_WORD];
    int count;
    struct StringCount* left;
    struct StringCount* right;
};


int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Missing text file that goes with %s\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    if(fp == NULL){
        perror("File Opening Error");
        exit(1);
    }

    struct StringCount *root = NULL;
    char word[50];

    // read words from Moby and insert them into the binary search tree
    while(fscanf(fp, "%s", word) == 1){
        root = insert(root, word);
    }

    fclose(fp);

    int choice = 0;
    char SearchWordInput[50];

    while(choice != 3){
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
                printf("Which Word Do You Want Me to Find: ");
                scanf("%s", SearchWordInput);
                printf("'%s' occurred %d times in the file.\n", SearchWordInput, searchWord(root, SearchWordInput));
                break;
            case 3:
                // quit the program
                break;
            default:
                printf("\nInvalid Choice.  Select Between 1-3 Only, Thanks!!\n");
        }

    };

    deleteTree(root);

    return 0;
}

// function to insert a word into the binary search tree
struct StringCount* insert(struct StringCount* root, const char* word){
    int cmp;

    if(root == NULL){
        // Create a new node if the tree is empty
        struct StringCount *newNode = (struct StringCount*)malloc(sizeof(struct StringCount));
            if(root == NULL){
                struct StringCount *newNode = (struct StringCount*)malloc(sizeof(struct StringCount));
                strcpy(newNode->word, word);
                newNode->count = 1;
                newNode->left = newNode->right = NULL;
                return newNode;
            }
    }

    cmp = strcmp(word, root->word);
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
void displayAllWords(struct StringCount *root){
    if(root != NULL){
        displayAllWords(root->left);
        //printf("Word: %s Count: %d\n", root->word, root->count);
        displayAllWords(root->right);
        printf("Word: %s \t\tCount: %d\n", root -> word, root -> count);
    }
}

// function to search for a specific word
int searchWord(struct StringCount *root, const char* word){
    int cmp;

    if(root == NULL){  // word not found
        return 0;
    }

    cmp = strcmp(word, root->word);
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
void deleteTree(struct StringCount *root){
    if(root != NULL){
        // traversal to delete and free memory
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}