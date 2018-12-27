#include <stdio.h>
#include<stdlib.h>

//Roland Benz 97923163
//gcc -o task04 task04.c

/* Write a C program that extends the binary search tree
defined in the previous tasks and includes the functions:
(see forward declarations)
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
void print_tree(struct TreeNode** pp);
void print_in_order(struct TreeNode** pp);

//forward declarations (task03)
void insert(struct TreeNode** pp, int key);
void delete_tree(struct TreeNode** pp);

int main(void)
{
    printf("Hello from task 4!\n");
    printf("\n\n~~~~~~~~~~~~~~~~~~~~insert()~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //Insert the keys 5, 3, 4, 9, 7, 8, 10, 13, 0, 6 into an empty tree.
    int key=0;
    struct TreeNode* root1=NULL;
    if(debug) printf("\n     info main: pointer addresses: &root1 = %x, root1 = %x\n", (int)&root1, (int)root1);
    printf("\n insert key=5\n");
    key=5;insert(&root1,key);
    printf("\n insert key=3\n");
    key=3;insert(&root1,key);
    printf("\n insert key=4\n");
    key=4;insert(&root1,key);
    printf("\n insert key=9\n");
    key=9;insert(&root1,key);
    printf("\n insert key=7\n");
    key=7;insert(&root1,key);
    printf("\n insert key=8\n");
    key=8;insert(&root1,key);
    printf("\n insert key=10\n");
    key=10;insert(&root1,key);
    printf("\n insert key=13\n");
    key=13;insert(&root1,key);
    printf("\n insert key=0\n");
    key=0;insert(&root1,key);
    printf("\n insert key=6\n");
    key=6;insert(&root1,key);

    printf("\n\n~~~~~~~~~~~~~~~~~~print_tree()~~~~~~~~~~~~~~~~~~~~\n");
    //Print the resulting tree using the function printTree.
    printf("\n graph g {\n");
    print_tree(&root1);
    printf(" }\n");

    printf("\n\n~~~~~~~~~~~~~~print_in_order()~~~~~~~~~~~~~~~~~~~~~\n");
    //Print the resulting tree using the function printInOrder.
    printf("\n start print_in_order:\n");
    print_in_order(&root1);
    printf(" end print_in_order");

    printf("\n\n~~~~~~~~~~~~~~~~~delete_tree()~~~~~~~~~~~~~~~~~~~~~~~\n");
    //Delete the tree.
    delete_tree(&root1);

    printf("\n\n~~~~~~~~~~~~~~~~~print_tree()~~~~~~~~~~~~~~~~~~~~~~~\n");
    //Print the resulting tree using the function printTree.
    printf("\n graph g {\n");
    print_tree(&root1);
    printf(" }\n");
    root1=NULL;
    printf("\n graph g {\n");
    print_tree(&root1);
    printf(" }\n");

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}

void print_tree(struct TreeNode** pp){
/*printTree which prints a given tree in the console. The printing format
should be graph g { (all the edges in the form NodeA -- NodeB) }, where
each edge should be printed on a separate line. The ordering of the edges
is not relevant.
graph g {
5 -- 2
5 -- 7
7 -- 6
7 -- 8
}
*/
    //if Null
    if ((*pp)==NULL){return;}

    //recursive traversal
    if(debug) printf("\n     info1 print_tree: pointer addresses:\n     &(*pp) = %x, (*pp) = %x, &(*pp)->key = %x, (*pp)->key = %d\n", (int)&(*pp), (int)(*pp), (int)&(*pp)->key, (int)(*pp)->key);
    if ((*pp)->l_child!=NULL){
        if(debug) printf("\n     info2 print_tree: pointer addresses:\n     &(*pp)->l_child = %x, (*pp)->l_child = %x\n", (int)&(*pp)->l_child, (int)(*pp)->l_child);
        print_tree(&(*pp)->l_child);
    }
    if ((*pp)->r_child!=NULL){
        if(debug) printf("\n     info3 print_tree: pointer addresses:\n     &(*pp)->r_child = %x, (*pp)->r_child = %x\n", (int)&(*pp)->r_child, (int)(*pp)->r_child);
        print_tree(&(*pp)->r_child);
    }

    //print
    if ((*pp)->l_child!=NULL){
        printf("   %d -- %d \n", (int)(*pp)->key, (int)(*pp)->l_child->key);
    }
    if ((*pp)->r_child!=NULL){
        printf("   %d -- %d \n", (int)(*pp)->key, (int)(*pp)->r_child->key);
    }
    if(debug) printf("\n     info4 print_tree: (*pp)->key=%d \n", (int)(*pp)->key);
}

void print_in_order(struct TreeNode** pp){
/*printInOrder which traverses a given tree in-order and prints the keys of
all the nodes.
*/
    //recursive traversal

    //left child
    if(debug) printf("\n     info1 print_tree: pointer addresses:\n     &(*pp) = %x, (*pp) = %x, &(*pp)->key = %x, (*pp)->key = %d\n", (int)&(*pp), (int)(*pp), (int)&(*pp)->key, (int)(*pp)->key);
    if ((*pp)->l_child!=NULL){
        if(debug) printf("\n     info2 print_tree: pointer addresses:\n     &(*pp)->l_child = %x, (*pp)->l_child = %x\n", (int)&(*pp)->l_child, (int)(*pp)->l_child);
        print_in_order(&(*pp)->l_child);
    }

    //print
    printf("   key: %d \n", (int)(*pp)->key);

    //right child
    if ((*pp)->r_child!=NULL){
        if(debug) printf("\n     info3 print_tree: pointer addresses:\n     &(*pp)->r_child = %x, (*pp)->r_child = %x\n", (int)&(*pp)->r_child, (int)(*pp)->r_child);
        print_in_order(&(*pp)->r_child);
    }
    if(debug) printf("\n     info4 print_tree: (*pp)->key=%d \n", (int)(*pp)->key);
}

//Task03
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
        if(debug) printf("\n     info2 insert: pointer addresses:\n     &(*pp) = %x, (*pp) = %x, (*pp)->key = %d\n     &(*pp)->l_child = %x, (*pp)->l_child = %x\n     &(*pp)->r_child = %x, (*pp)->r_child = %x\n", (int)&(*pp), (int)(*pp), (*pp)->key, (int)&(*pp)->l_child, (int)(*pp)->l_child, (int)&(*pp)->r_child, (int)(*pp)->r_child);
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

    if(debug) printf("\n     info1 delete: pointer addresses:\n     &(*pp) = %x, (*pp) = %x, &(*pp)->key = %x, (*pp)->key = %d\n", (int)&(*pp), (int)(*pp), (int)&(*pp)->key, (int)(*pp)->key);

    //go left
    if ((*pp)->l_child!=NULL){
        if(debug) printf("\n     info2 delete: pointer addresses:\n     &(*pp)->l_child = %x, (*pp)->l_child = %x\n", (int)&(*pp)->l_child, (int)(*pp)->l_child);
        delete_tree(&(*pp)->l_child);
    }

    //go right
    if ((*pp)->r_child!=NULL){
        if(debug) printf("\n     info3 delete: pointer addresses:\n     &(*pp)->r_child = %x, (*pp)->r_child = %x\n", (int)&(*pp)->r_child, (int)(*pp)->r_child);
        delete_tree(&(*pp)->r_child);
    }

    //free the leave
    if(debug) printf("\n     info4 delete: pointer addresses:\n     &(*pp) = %x, (*pp) = %x, &(*pp)->key = %x, (*pp)->key = %d\n", (int)&(*pp), (int)(*pp), (int)&(*pp)->key, (int)(*pp)->key);
    printf("\n   info delete_tree: freed node= %d", (*pp)->key);

    free((*pp));

}
