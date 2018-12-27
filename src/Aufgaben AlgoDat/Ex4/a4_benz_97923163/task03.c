#include <stdio.h>
#include<stdlib.h>

//Roland Benz 97923163
//gcc -o task03 task03.c

/*BINARY SEARCH TREE
Use the node-definition and create multiple tree
instances.
*/

/*Memory (die Adressen 1 6 7 9 10 12 13 usw werden an pp übergeben
 *und wenn deren Value NULL mit den Adressen der Kinder gefüllt)
Variable    s   pp  p   e     TreeN     TreeN     TreeN  ...    TreeN      TreeN
Address     1   2   3   4     5 6 7     8 9 10    11 12 13      26 27 28   29 30 31
Value       5   1               8 11
*/

//change to 1 do print memory information
#define debug 0

//data structure
struct TreeNode {
    int key;
    struct TreeNode* l_child;
    struct TreeNode* r_child;
};

//forward declarations
void insert(struct TreeNode** pp, int key);
void delete_tree(struct TreeNode** pp);

int main(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task 3!\n");

    //Create an empty tree root1 and insert the keys 4, 2, 3, 8, 6, 7, 9, 12, 1.
    int key=0;
    struct TreeNode* root1=NULL;
    if(debug) printf("\n     info main: pointer addresses: &root1 = %x, root1 = %x\n", (int)&root1, (int)root1);
    printf("\n insert key=4\n");
    key=4;insert(&root1,key);
    printf("\n insert key=2\n");
    key=2;insert(&root1,key);
    printf("\n insert key=3\n");
    key=3;insert(&root1,key);
    printf("\n insert key=8\n");
    key=8;insert(&root1,key);
    printf("\n insert key=6\n");
    key=6;insert(&root1,key);
    printf("\n insert key=7\n");
    key=7;insert(&root1,key);
    printf("\n insert key=9\n");
    key=9;insert(&root1,key);
    printf("\n insert key=12\n");
    key=12;insert(&root1,key);
    printf("\n insert key=1\n");
    key=1;insert(&root1,key);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    //Create an empty tree root2 and insert the keys 3, 8, 10, 1, 7.
    struct TreeNode* root2=NULL;
    if(debug) printf("\n     info main: pointer addresses: &root2 = %x, root2 = %x\n", (int)&root2, (int)root2);
    printf("\n insert key=3\n");
    key=3;insert(&root2,key);
    printf("\n insert key=8\n");
    key=8;insert(&root2,key);
    printf("\n insert key=10\n");
    key=10;insert(&root2,key);
    printf("\n insert key=1\n");
    key=1;insert(&root2,key);
    printf("\n insert key=7\n");
    key=7;insert(&root2,key);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    //Delete the tree root1.
    delete_tree(&root1);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    //Delete the tree root2.
    delete_tree(&root2);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;

}

void insert(struct TreeNode** pp, int key){
/*the function insert which gets the root of a tree and a value key as an
input and inserts a node with the value key into the proper position of
the given binary search tree.*/

    if(debug) printf("\n     info1 insert: pointer addresses: &pp = %x, pp = %x\n", (int)&pp, (int)pp);
    if((*pp)==NULL){
        (*pp) = (struct TreeNode* )malloc(sizeof(struct TreeNode));
        (*pp)->key = key;
        (*pp)->l_child = NULL;
        (*pp)->r_child = NULL;
        printf("   info insert: inserted value= %d", key);
        if(debug) printf("\n     info2 insert: pointer addresses:\n     &(*pp) = %x, (*pp) = %x, (*pp)->key = %x\n     &(*pp)->l_child = %x, (*pp)->l_child = %x\n     &(*pp)->r_child = %x, (*pp)->r_child = %x\n", (int)&(*pp), (int)(*pp), (*pp)->key, (int)&(*pp)->l_child, (int)(*pp)->l_child, (int)&(*pp)->r_child, (int)(*pp)->r_child);
    }
    else if (key < (*pp)->key){
        if(debug) printf("\n     info3 insert: pointer addresses:\n     &(*pp)->l_child = %x, (*pp)->l_child = %x\n", (int)&(*pp)->l_child, (int)(*pp)->l_child);
        insert(&(*pp)->l_child, key );
    }
    else{
        if(debug) printf("\n     info4 insert: pointer addresses:\n     &(*pp)->r_child = %x, (*pp)->r_child = %x\n", (int)&(*pp)->r_child, (int)(*pp)->r_child);
        insert(&(*pp)->r_child, key );
    }

}

void delete_tree(struct TreeNode** pp){
/*the function deleteTree which gets the root of a tree as an input, removes
all the nodes of the tree and sets its root to NULL.*/

    if(debug) printf("\n     info1 delete: pointer addresses:\n     &(*pp) = %x, (*pp) = %x, &(*pp)->key = %x, (*pp)->key = %x\n", (int)&(*pp), (int)(*pp), (int)&(*pp)->key, (int)(*pp)->key);
    if ((*pp)->l_child!=NULL){
        if(debug) printf("\n     info2 delete: pointer addresses:\n     &(*pp)->l_child = %x, (*pp)->l_child = %x\n", (int)&(*pp)->l_child, (int)(*pp)->l_child);
        delete_tree(&(*pp)->l_child);
    }
    if ((*pp)->r_child!=NULL){
        if(debug) printf("\n     info3 delete: pointer addresses:\n     &(*pp)->r_child = %x, (*pp)->r_child = %x\n", (int)&(*pp)->r_child, (int)(*pp)->r_child);
        delete_tree(&(*pp)->r_child);
    }
    if(debug) printf("\n     info4 delete: pointer addresses:\n     &(*pp) = %x, (*pp) = %x, &(*pp)->key = %x, (*pp)->key = %x\n", (int)&(*pp), (int)(*pp), (int)&(*pp)->key, (int)(*pp)->key);
    printf("\n   info delete_tree: freed node= %d", (*pp)->key);
    free((*pp));

}
