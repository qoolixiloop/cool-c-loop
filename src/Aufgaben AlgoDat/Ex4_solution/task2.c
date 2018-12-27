#include <stdlib.h>
#include <stdio.h>

// ... include code from Task 1 ... 

struct StackNode {
    int key;
    struct StackNode* next;
};

int isEmpty(struct StackNode* s)
{
    return !s;
}

void push(struct StackNode** s, int key)
{
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->key = key;
    stackNode->next = NULL;
    stackNode->next = *s;
    *s = stackNode;
}

int pop(struct StackNode** s)
{
    if (isEmpty(*s))
        return -1;
    struct StackNode* temp = *s;
    *s = (*s)->next;
    int popped = temp->key;
    free(temp);

    return popped;
}

void printStack(struct StackNode* s) {
    struct StackNode* temp = s;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

// ------------------------------ Task 2 --------------------------------------

int evaluatePostfix(char* exp)
{
    int i;
    int val1, val2;
    // Create an empty stack
    struct StackNode* s = NULL;

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
    char expr[100];
    int val;
    struct StackNode* s = NULL;

    printf("Type a postfix expression\n");
    scanf("%[0-9+/-*]s", expr);
    printf("Result: %d\n", evaluatePostfix(expr));
}

// Linux, Mac: gcc task2.c -o task2; ./task2
// Windows: gcc task2.c -o task2; task2
