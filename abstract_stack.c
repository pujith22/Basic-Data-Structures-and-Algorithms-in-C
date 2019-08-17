#include<stdio.h>
#include<stdlib.h>

typedef struct Stack_node
{
	void* data;
	struct Stack_node* next;
}stack_node;

typedef struct Stack
{
	stack_node* top;
}stack;

void initialize(stack* s)
{
	s->top = NULL;
}

int isEmpty(stack *s)
{
	if(s->top == NULL)
		return 1;
	else
		return 0;
}

void push(stack* s,void* data)
{
	stack_node* temp = (stack_node*)malloc(sizeof(stack_node));
	temp->data = data;
	temp->next = s->top;
	s->top = temp;
}

void* pop(stack* s)
{
	if(s->top == NULL)
		return NULL;
	else
	{
		void* data = s->top->data;
		s->top = s->top->next;
		return data;
	}
}