#include <stdio.h>
#include<stdlib.h>

//Roland Benz 97923163
//gcc -o task05 task05.c

/*Given a rooted tree T, the lowest common ancestor
(LCA) between two nodes n1 and n2 is defined as the lowest node in T that
has both n1 and n2 as descendants (where we allow a node to be a descendant
of itself). Consequently, the LCA of n1 and n2 in T is the shared ancestor of
n1 and n2 that is located farthest from the root.
*/

//change to 1 do print memory information
#define debug 0

//data structure
struct TreeNode {
    int key;
    struct TreeNode* l_child;
    struct TreeNode* r_child;
};

//forward declarations (task04)
void print_tree(struct TreeNode** pp);
void print_in_order(struct TreeNode** pp);

//forward declarations (task03)
void insert(struct TreeNode** pp, int key);
void delete_tree(struct TreeNode** pp);

//forward declarations
struct TreeNode* lca(struct TreeNode* p, int n1, int n2);


int main(void)
{
    printf("Hello from task 5!\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    //Create an empty tree and insert the nodes 7, 5, 6, 1, 9, 10, 8.
    int key=0;
    struct TreeNode* root1=NULL;
    if(debug) printf("\n     info main: pointer addresses: &root1 = %x, root1 = %x\n", (int)&root1, (int)root1);
    printf("\n insert key=7\n");
    key=7;insert(&root1,key);
    printf("\n insert key=5\n");
    key=5;insert(&root1,key);
    printf("\n insert key=6\n");
    key=6;insert(&root1,key);
    printf("\n insert key=1\n");
    key=1;insert(&root1,key);
    printf("\n insert key=9\n");
    key=9;insert(&root1,key);
    printf("\n insert key=10\n");
    key=10;insert(&root1,key);
    printf("\n insert key=8\n");
    key=8;insert(&root1,key);

    //Print the resulting tree using one of the methods described in Task 4.
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

    printf("\n\n~~~~~~~~~~~~~~LCA()~~~~~~~~~~~~~~~~~~~~~\n");
    //Print out the LCA of node 8 and node 9.
    int n1=8, n2=9;
    struct TreeNode* lca_root_of_n1_n2 = NULL;
    lca_root_of_n1_n2 = lca(root1, n1, n2);
    printf("\n lca_root_of_%d_%d = %d\n", n1, n2, lca_root_of_n1_n2->key);

    printf("\n\n~~~~~~~~~~~~~~LCA()~~~~~~~~~~~~~~~~~~~~~\n");
    //Print out the LCA of node 1 and node 6.
    n1=1; n2=6;
    lca_root_of_n1_n2 = lca(root1, n1, n2);
    printf("\n lca_root_of_%d_%d = %d\n", n1, n2, lca_root_of_n1_n2->key);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;

}

struct TreeNode* lca(struct TreeNode* p, int n1, int n2){
/*finds the Lowest Common Ancestor (LCA).
You may assume that both the values exist in the tree.
*/

    struct TreeNode* p_=p;
    //compare node key with n1 and n2
    int key=p->key;
    //n1,n2 both smaller than key: go left
    if (n1<key && n2<key){p_=lca(p->l_child, n1, n2);}
    //n1,n2 both larger than key: go right
    else if (n1>key && n2>key){p_=lca(p->r_child, n1, n2);}
    //n1,n2 not both smaller or larger than key: return node
    else{return p_;}

    return p_;
}

//Task04
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
