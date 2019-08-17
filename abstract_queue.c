#include<stdio.h>
#include<stdlib.h>

typedef struct Queue_node{
	void *data;
	struct Queue_node *next;
}queue_node;

typedef struct Queue{
	queue_node* head;
	queue_node* tail;
}queue;

void initialize(queue *q)
{
	q->head=q->tail=NULL;
}

void enqueue(queue *q, void* data)
{
	queue_node* temp = (queue_node*)malloc(sizeof(queue_node));
	temp->data = data;
	temp->next = NULL;
	if(q->head==NULL)
		q->head=q->tail=temp;
	else{
		q->tail->next = temp;
		q->tail = q->tail->next;
	}
}

void* dequeue(queue* q)
{
	if(q->head==NULL)
		return NULL;
	else{
		queue_node* temp = q->head;
		q->head = q->head->next;
		return temp->data;
	}
}

int isEmpty(queue *q)
{
	if(q->head == NULL)
		return 1;
	else
		return 0;
}

/*void printQueue(queue* q)
{
	queue_node * temp = q->head;
	while(temp!=NULL)
	{
		printf("%d -> ",*((int*)temp->data));
		temp=temp->next;
	}
}*/

void main()
{
	queue q1,q2;
	initialize(&q1);
	initialize(&q2);
	int a=5,b=6,c=7,d=8;
	float p=8.7,q=0.6,r=9.7,s=7.8;
	enqueue(&q1,&a);
	enqueue(&q1,&b);
	enqueue(&q1,&c);
	enqueue(&q1,&d);
	enqueue(&q2,&p);
	enqueue(&q2,&q);
	enqueue(&q2,&r);
	enqueue(&q2,&s);
	printQueue(&q1);
	printf("\n%f",*((float*)dequeue(&q2)));
	printf("\n%d\n",*((int*)dequeue(&q1)));
	printQueue(&q1);

}


