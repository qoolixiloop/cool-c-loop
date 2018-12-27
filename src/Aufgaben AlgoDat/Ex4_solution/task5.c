#include <stdlib.h>
#include <stdio.h>

// ... include code from Task 3 ... 

struct TreeNode {
    int key;
    struct TreeNode* lChild;
    struct TreeNode* rChild;
};

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

void printTreeRecursive(struct TreeNode *root) {
    if (root == NULL)
        return;
    if (root->lChild != NULL) {
        printf("  %d -- %d\n", root->key, root->lChild->key);
        printTreeRecursive(root->lChild);
    }
    if(root->rChild != NULL) {
        printf("  %d -- %d\n", root->key, root->rChild->key);
        printTreeRecursive(root->rChild);
    }
}

void printTree(struct TreeNode *root) {
    printf("graph g {\n");
    printTreeRecursive(root);
    printf("}\n");
}

// ----------------------------- Task 5 ---------------------------------------

/* Function to find LCA of n1 and n2. The function assumes that both
  n1 and n2 are present in BST */
struct TreeNode *lca(struct TreeNode *root, int n1, int n2)
{
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->key > n1 && root->key > n2)
        return lca(root->lChild, n1, n2);

    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->key < n1 && root->key < n2)
        return lca(root->rChild, n1, n2);

    return root;
}

void main() {
    int n1, n2;
    struct TreeNode *t;
    struct TreeNode *root = NULL;

    insert(7, &root);
    insert(5, &root);
    insert(6, &root);
    insert(1, &root);
    insert(9, &root);
    insert(10, &root);
    insert(8, &root);

    printTree(root);

    n1 = 8;
    n2 = 9;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->key);
    n1 = 1;
    n2 = 6;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->key);

}

// Linux, Mac: gcc task5.c -o task5; ./task5
// Windows: gcc task5.c -o task5; task5
