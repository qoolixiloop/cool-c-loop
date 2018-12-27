#include <stdio.h>
#include<stdlib.h>
//Roland Benz 97923163
//gcc -o task01 task01.c

/*STACK IMPLEMENTED AS LINKED LIST
Create a new datatype stack of positive integers that is
able to store an arbitrary number of elements.
Along with the above datatype create the following functions:
(see forward declarations)
*/

/*Memory (um den Value von Variable s auf ein neues stack Element zu setzen wird pp benötigt)
Variable    s   pp  p   e   stack   stack   stack  ...  stack    stack
Address     1   2   3   4   5 6     7 8     9 10        20 21    22 23
Value       22  1   22  22  3 NULL  4 5     6 7         17 18    30 20
Print 30 17 ... 4 3
*/

//change to 1 do print memory information
#define debug 0

//data structure
struct stack {
    int key;
    struct stack* next;
};

//forward declarations
int is_empty(struct stack* p);
void push(struct stack** pp, int key);
int pop(struct stack** pp);
void print_stack(struct stack* p);


int main(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task 1!\n");

    //Create stack s;
    struct stack* s = NULL;
    if(debug) printf("\n     info main: pointer addresses: &s = %x, s = %x\n", (int)&s, (int)s);
    int out=0;
    out = is_empty(s); printf("\n <0>=yes, <1>=no, is stack empty? = %d\n", out);

    //Push 3, 4, 6, 9, 10 into s.
    int key=0;
    printf("\n push key=3\n");
    key=3; push(&s, key);
    if(debug) printf("\n     info main: pointer addresses: &s = %x, s = %x\n", (int)&s, (int)s);
    printf("\n push key=4\n");
    key=4; push(&s, key);
    if(debug) printf("\n     info main: pointer addresses: &s = %x, s = %x\n", (int)&s, (int)s);
    printf("\n push key=6\n");
    key=6; push(&s, key);
    if(debug) printf("\n     info main: pointer addresses: &s = %x, s = %x\n", (int)&s, (int)s);
    printf("\n push key=9\n");
    key=9; push(&s, key);
    if(debug) printf("\n     info main: pointer addresses: &s = %x, s = %x\n", (int)&s, (int)s);
    printf("\n push key=10\n");
    key=10; push(&s, key);
    if(debug) printf("\n     info main: pointer addresses: &s = %x, s = %x\n", (int)&s, (int)s);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //Pop two elements and print their values.
    int poped1=0, poped2=0;
    printf("\n pop key=%d\n", s->key);
    poped1 = pop(&s);
    printf("\n pop key=%d\n", s->key);
    poped2 = pop(&s);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //Push 4, 17, 30.
    printf("\n push key=4\n");
    key=4; push(&s, key);
    if(debug) printf("\n     info main: pointer addresses: &s = %x, s = %x\n", (int)&s, (int)s);
    printf("\n push key=17\n");
    key=17; push(&s, key);
    if(debug) printf("\n     info main: pointer addresses: &s = %x, s = %x\n", (int)&s, (int)s);
    printf("\n push key=30\n");
    key=30; push(&s, key);
    if(debug) printf("\n     info main: pointer addresses: &s = %x, s = %x\n", (int)&s, (int)s);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //Print s
    out = is_empty(s); printf("\n <0>=yes, <1>=no, is stack empty? = %d\n", out);
    print_stack(s);
    printf("\n poped values %d, %d\n", poped1,poped2);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;

}

int is_empty(struct stack* p){
/*which checks if stack s is empty or not.
*/
    if (p==NULL){return 0;}
    return 1;
}
void push(struct stack** pp, int key){
/*which inserts element key into s.
*/

    if(debug) printf("\n     info push: pointer addresses: &pp = %x, pp = %x\n", (int)&pp, (int)pp);

    //new element
    struct stack* e;
    e = (struct stack* )malloc(sizeof(struct stack));
    e->key = key;
    e->next = NULL;
    if(debug) printf("\n     info push: pointer addresses: &e = %x, e = %x, e->key = %d\n", (int)&e, (int)e, e->key);

    //insert new element at root of linked list
    if ((*pp)== NULL){
        e->next = NULL;
        (*pp) = e;
    }
    else{
        e->next = (*pp);
        (*pp) = e;
    }
    printf("   info push: pushed value= %d",key);
}

int pop(struct stack** pp){
/*which removes the last inserted element from s
and returns its value. In case of an error, -1 should be returned.
*/
    if(debug) printf("\n     info pop: pointer addresses: &pp = %x, pp = %x\n", (int)&pp, (int)pp);
    if(debug) printf("\n     info pop: pointer addresses: pp = %x, (*pp) = %x\n", (int)pp, (int)(*pp));

    int key;
    struct stack* tmp;

    if ((*pp)== NULL){
        return -1;
    }
    else{
        key=(*pp)->key;
        tmp=(*pp);
        (*pp)=(*pp)->next;
        free(tmp);
    }
    if(debug) printf("\n     info pop: pointer addresses: pp = %x, (*pp) = %x\n", (int)pp, (int)(*pp));
    printf("   info pop: poped value= %d",key);
    return key;
}

void print_stack(struct stack* p){
/*which prints the values of the stack s.
*/
    printf("\n info print_stack: start\n");
    while(p!=NULL){
        if(debug) printf("\n     info print: pointer addresses: &p = %x, p = %x\n", (int)&p, (int)p);
        printf("   key = %d\n", p->key);
        p=p->next;
    }
    printf(" info print_stack: end \n");
}
