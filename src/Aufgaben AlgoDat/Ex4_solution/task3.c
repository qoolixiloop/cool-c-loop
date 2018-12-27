#include<stdlib.h>
#include<stdio.h>

struct TreeNode {
    int key;
    struct TreeNode* lChild;
    struct TreeNode* rChild;
};

/* See slides, there is also a recursive variation. */
void insert(int key, struct TreeNode ** root) {
    struct TreeNode *nodeToInsert = malloc(sizeof(struct TreeNode));
    nodeToInsert->key = key;
    nodeToInsert->lChild = NULL;
    nodeToInsert->rChild = NULL;
    
    struct TreeNode *oneDelayed = NULL;
    struct TreeNode *insertPlace = *root;
    while (insertPlace != NULL) {
        oneDelayed = insertPlace;
        if (insertPlace->key < nodeToInsert->key)
            insertPlace = insertPlace->rChild;
        else
            insertPlace = insertPlace->lChild;
    }
    if (oneDelayed == NULL)
        *root = nodeToInsert;
    else if (oneDelayed->key < nodeToInsert->key)
        oneDelayed->rChild = nodeToInsert;
    else
        oneDelayed->lChild = nodeToInsert;
}

void deleteTree(struct TreeNode ** root) {
    /* Post order tree walk */
    if(*root == NULL) return;
    deleteTree(&(*root)->lChild);
    deleteTree(&(*root)->rChild);
    free(*root);
    *root=NULL;
}

void main() {
    struct TreeNode *root1;
    root1 = NULL;
    struct TreeNode *root2;
    root2 = NULL;

    insert(4, &root1);
    insert(2, &root1);
    insert(3, &root1);
    insert(8, &root1);
    insert(6, &root1);
    insert(7, &root1);
    insert(9, &root1);
    insert(12, &root1);
    insert(1, &root1);

    insert(3, &root2);
    insert(8, &root2);
    insert(10, &root2);
    insert(1, &root2);
    insert(7, &root2);

    deleteTree(&root1);
    deleteTree(&root2);
}

// Linux, Mac: gcc task3.c -o task3; ./task3
// Windows: gcc task3.c -o task3; task3
