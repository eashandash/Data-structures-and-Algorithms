

// queue implementation using linked list (singly linked list)

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
} *rear=NULL, *front;

void enqueue(value)
{
	struct node *new_node;
	new_node=malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;

	if (rear==NULL)
	{
		front=new_node;
		rear=new_node;
	}
	else
	{
		rear->next=new_node;
		rear=new_node;
	}
}

int dequeue()
{
	struct node *current;

	if(front==rear) // only one node
	{
		front=NULL;
		rear=NULL;
		free(front);
		return 0;
	}
	else
	{
		current=front;
		front=current->next;
		free(current);
		return 0;
	}

}



void display()
{
	struct node *current;
	current=front;
	if (current==NULL)
	{
		printf("the list is empty");
	}
	else
	{
		while(current != NULL)
		{
			printf(" %d ->",current->data);
			current=current->next;
		}
		printf("NULL \n");
	}
}


main()
{
	int value,op;
	while(1)
	{
		printf("Enter the option:\t 1. enqueue \t 2. dequeue \t 3. exit");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("enter the value:");
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

