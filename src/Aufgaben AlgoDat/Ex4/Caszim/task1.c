// Cazim Hysi 14-731-939

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct stack {
	int key;
	struct stack* next;
};

typedef struct stack* Stack;

Stack new_stack(int key)
{
	Stack s = (Stack) malloc(sizeof(struct stack));
	s->key = key;
	s->next = NULL;
	return s;
}

int isEmpty(Stack s)
{
	if (s == NULL)
		return 1;
	else
		return 0;
}

void free_stack(Stack s)
{
	free(s);
	s = NULL;
}

void destroyStack(Stack* s)
{
	while(*s != NULL)
	{
		Stack nxt = (*s)->next;
		free_stack(*s);
		*s = nxt;
	}
}

void push(Stack* s, int key)
{
	Stack node = new_stack(key);
	if (node == NULL)
	{
		fprintf(stderr, "Error: out of memory!");
		exit(-1);
	}
	node->next = *s;
	*s = node;
}

int pop(Stack* s)
{
	int key = (*s)->key;
	Stack nxt = (*s)->next;
	free_stack(*s);
	*s = nxt;
	return key;
}

void printStack(Stack s)
{
	Stack curr = s;
	printf("Stack s:\n");
	while (curr != NULL)
	{
		printf("%d\n", curr->key);
		curr = curr->next;
	}
}

int main(int argc, const char* argv[])
{
	int val1;
	int val2;

	Stack stk = NULL;
	Stack* s = &stk;
	push(s, 3);
	push(s, 4);
	push(s, 6);
	push(s, 9);
	push(s, 10);

	val1 = pop(s);
	val2 = pop(s);
	printf("%d %d\n", val1, val2);

	push(s, 4);
	push(s, 17);
	push(s, 30);

	printStack(*s);
	destroyStack(s);
}
