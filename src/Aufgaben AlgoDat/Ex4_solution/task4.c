#include <stdlib.h>
#include <stdio.h>

// ... include code from Task 3 ... 

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
        if(insertPlace->key < nodeToInsert->key)
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

// ----------------------------- Task 4 ---------------------------------------

void deleteTree(struct TreeNode ** root) {
    /* Post order tree walk */
    if (*root == NULL)
        return;
    deleteTree(&(*root)->lChild);
    deleteTree(&(*root)->rChild);
    free(*root);
    *root=NULL;
}

void printTreeRecursive(struct TreeNode *root) {
    if (root == NULL)
        return;
    if (root->lChild != NULL) {
        printf("  %d -- %d\n", root->key, root->lChild->key);
        printTreeRecursive(root->lChild);
    }
    if (root->rChild != NULL) {
        printf("  %d -- %d\n", root->key, root->rChild->key);
        printTreeRecursive(root->rChild);
    }
}

void printTree(struct TreeNode *root) {
    printf("graph g {\n");
    printTreeRecursive(root);
    printf("}\n");
}

void printInOrderRecursive(struct TreeNode *root) {
    if (root == NULL)
        return;
    printInOrderRecursive(root->lChild);
    printf("%d ", root->key);
    printInOrderRecursive(root->rChild);
}

void printInOrder(struct TreeNode *root) {
    printInOrderRecursive(root);
    printf("\n");
}

void main() {
    struct TreeNode *root;
    root = NULL;
    insert(5, &root);
    insert(3, &root);
    insert(4, &root);
    insert(9, &root);
    insert(7, &root);
    insert(8, &root);
    insert(10, &root);
    insert(13, &root);
    insert(0, &root);
    insert(6, &root);

    printTree(root);

    printInOrder(root);

    deleteTree(&root);

    printTree(root);
}

// Linux, Mac: gcc task4.c -o task4; ./task4
// Windows: gcc task4.c -o task4; task4
