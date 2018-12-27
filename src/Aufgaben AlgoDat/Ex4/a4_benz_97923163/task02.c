#include <stdlib.h>
#include <stdio.h>
//Roland Benz 97923163
//Mit grosszügiger Unterstützung von Cazim Hysi 14-731-939
//gcc -o task02 task02.c

/*Postfix notation is a mathematical notation used to
represent algebraic expressions. In postfix each operator follows their operands;
for instance, to add 3 and 4, one would write ”3 4 +” rather than ”3 + 4” (infix
notation). If there are multiple operators, each operator is given immediately
after its second operand. So the expression written ”3 - 4 + 5”, in conventional
(infix) notation, is written ”3 4 - 5 +” in postfix notation. 4 is first subtracted
from 3, then 5 is added to the first result. An advantage of postfix notation is
that it removes the need for parentheses that are required by infix. For example
”3 - 4 * 5” (infix) can also be written ”3 - (4 * 5)”, that means something quite
different from ”(3 - 4) * 5”. In postfix the former is written ”3 4 5 * -”, which
unambiguously means ”3 (4 5 *) -” and the latter is written ”3 4 - 5 *”, which
unambiguously means ”(3 4 -) 5 *”.
Here are steps for evaluating a postfix expression:
• Create a stack to store operands.
• Scan the given expression and do the following for every scanned element.
– If the element is a number, push it into the stack.
– If the element is an operator, pop two operands from the stack, eval-
uate the operator, and push the result back to the stack.
• When the whole expression is scanned, the number in the stack is the final
answer.
*/

//data structure
struct stack {
    int key;
    struct stack* next;
};

typedef struct stack* Stack;

//forward declarations
int evaluatePostfix(char* exp);


//change to 1 do print memory information
#define debug 0

//data structure


//forward declarations
int evaluatePostfix(char* exp);
Stack new_stack(int key);
int isEmpty(Stack s);
void free_stack(Stack s);
void destroyStack(Stack* s);
void push(Stack* s, int key);
int pop(Stack* s);
void printStack(Stack s);
int evaluatePostfix(char* exp);

int main(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task 2!\n");
    printf("Mit grosszügiger Unterstützung von Cazim Hysi 14-731-939\n");

    //Write a program in C to evaluate these 3 postfix expressions:
    //231 ∗ +9−
    //128 ∗ +3−
    //25 ∗ 32 + /

    int res1;
    int res2;
    int res3;

    char* exp1 = "231*+9-";
    char* exp2 = "128*+3-";
    char* exp3 = "25*32+/";

    res1 = evaluatePostfix(exp1);
    res2 = evaluatePostfix(exp2);
    res3 = evaluatePostfix(exp3);

    printf("The value of expression %s is %d\n", exp1, res1);
    printf("The value of expression %s is %d\n", exp2, res2);
    printf("The value of expression %s is %d\n", exp3, res3);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;

}

//Algos and auxiliary functions
Stack new_stack(int key){

    Stack s = (Stack) malloc(sizeof(struct stack));
    s->key = key;
    s->next = NULL;
    return s;
}

int isEmpty(Stack s){

    if (s == NULL)
        return 1;
    else
        return 0;
}

void free_stack(Stack s){

    free(s);
    s = NULL;
}

void destroyStack(Stack* s){

    while(*s != NULL)
    {
        Stack nxt = (*s)->next;
        free_stack(*s);
        *s = nxt;
    }
}

void push(Stack* s, int key){

    Stack node = new_stack(key);
    if (node == NULL)
    {
        fprintf(stderr, "Error: out of memory!");
        exit(-1);
    }
    node->next = *s;
    *s = node;
}

int pop(Stack* s){

    if (*s == NULL)
    {
        fprintf(stderr, "Error: attempt to pop from empty stack!");
        exit(-1);
    }
    int key = (*s)->key;
    Stack nxt = (*s)->next;
    free_stack(*s);
    *s = nxt;
    return key;
}

void printStack(Stack s){

    Stack curr = s;
    printf("Stack s:\n");
    while (curr != NULL)
    {
        printf("%d\n", curr->key);
        curr = curr->next;
    }
}
int evaluatePostfix(char* exp){

    Stack stk = NULL;
    Stack* s = &stk;

    int val1;
    int val2;
    int res;

    char curr = *exp;
    while (curr != '\0')
    {
        switch (curr)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                res = curr - '0';
                push(s, res);
                break;
            case '/':
                val1 = pop(s);
                val2 = pop(s);
                res = val2 / val1;
                push(s, res);
                break;
            case '*':
                val1 = pop(s);
                val2 = pop(s);
                res = val2 * val1;
                push(s, res);
                break;
            case '+':
                val1 = pop(s);
                val2 = pop(s);
                res = val2 + val1;
                push(s, res);
                break;
            case '-':
                val1 = pop(s);
                val2 = pop(s);
                res = val2 - val1;
                push(s, res);
                break;
            default:
                fprintf(stderr, "Error: unknown character!");
                exit(-1);
        }
        curr = *++exp;
    }
    res = pop(s);
    destroyStack(s);
    return res;
}


