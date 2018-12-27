// Cazim Hysi 14-731-939

#include <stdlib.h>
#include <stdio.h>

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
int evaluatePostfix(char* exp)
{
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

int main(int argc, const char *argv[])
{
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
}

