

// Queue implemetation using circular linked list (singly linked list) , only one pointer is maintained called rear

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
} *rear=NULL;


void enqueue(value)
{
	struct node *new_node;
	new_node=malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;

	if(rear==NULL)
	{
		rear=new_node;
		rear->next=rear;
	}
	else
	{
		new_node->next=rear->next;
		rear->next=new_node;
		rear=new_node;
	}
}

int dequeue()
{
	struct node *front;

	if (rear==NULL) // list is null
	{
		printf("No elements in queue to dequeue");
	}
	else if (rear->next == rear) //only one node
	{
		free(rear); //return memory to system
		rear = NULL;
		return 0;
	}
	else
	{
		front=rear->next;
		rear->next=front->next;
		free(front);
		return 0;

	}

}

void display()
{
	struct node *current;
	current=rear;

	if (current == NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		current= rear->next; // points to front element

		while(current != rear)
		{
			printf("%d ->",current->data);
			current=current->next;

		}
		printf("%d",current->data);
		printf("->NULL \n\n");

	}
}

main()
{
	int value,op;
	while(1)
	{
		printf("Enter your chice:\t 1. Enqueue \t 2. Dequeue 3. Exit");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				printf("Enter the number:");
				scanf("%d",&value);
				enqueue(value);
				display();
				break;
				case 2:
					dequeue();
					display();
					break;
					case 3:
						exit(0);

		}
	}
}

