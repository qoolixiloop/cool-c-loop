#include <stdlib.h>
#include <stdio.h>

struct stack {
    int key;
    struct stack* next;
};

int isEmpty(struct stack* s)
{
    return !s;
}

void push(struct stack** s, int key)
{
    struct stack* stackNode = (struct stack*) malloc(sizeof(struct stack));
    stackNode->key = key;
    stackNode->next = NULL;
    stackNode->next = *s;
    *s = stackNode;
}

int pop(struct stack** s)
{
    if (isEmpty(*s))
        return -1;
    struct stack* temp = *s;
    *s = (*s)->next;
    int popped = temp->key;
    free(temp);

    return popped;
}

void printStack(struct stack* s) {
    struct stack* temp = s;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int evaluatePostfix(char* exp)
{
    int i;
    int val1, val2;
    // Create an empty stack
    struct stack* s = NULL;

    // Scan all characters one by one
    for (i = 0; exp[i] != '\0'; i++)
    {
        if ('0' <= exp[i] && exp[i] <= '9')
            // If the scanned character is an operand (number) push it to
            // the stack.
            push(&s, exp[i] - '0'); // TODO atoi
        else
        {
            // If the scanned character is an operator, pop two
            // elements from the stack and apply the operator
            val1 = pop(&s);
            val2 = pop(&s);
            switch (exp[i])
            {
                case '+': push(&s, val2 + val1); break;
                case '-': push(&s, val2 - val1); break;
                case '*': push(&s, val2 * val1); break;
                case '/': push(&s, val2/val1);  break;
            }
        }
    }
    return pop(&s);
}

void main() {
    int val;
    struct stack* s = NULL;

    push(&s, 3);
    push(&s, 4);
    push(&s, 6);
    push(&s, 9);
    push(&s, 10);

    val = pop(&s);
    printf("%d\n", val);
    val = pop(&s);
    printf("%d\n", val);

    push(&s, 4);
    push(&s, 17);
    push(&s, 30);

    printStack(s);
}

// Linux, Mac: gcc task1.c -o task1; ./task1
// Windows: gcc task1.c -o task1; task1
