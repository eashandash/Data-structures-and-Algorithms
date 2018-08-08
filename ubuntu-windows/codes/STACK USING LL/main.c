

// stack implementation using linked list (singly linked lsit)

#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;
}*top=NULL;

void push(value)
{
	struct stack *new_node;
	new_node=malloc(sizeof(struct stack));
	new_node->data=value;
	new_node->next=NULL;

	if(top==NULL)
	{
		top=new_node;
	}
	else
	{
		new_node->next=top;
		top=new_node;
	}

}

void display()
{
	struct stack *current;
	current=top;

	if(current==NULL)
	{
		printf("The list is empty");
	}
	else
	{
		while(current != NULL)
		{
			printf("%d ->", current->data);
			current=current->next;
		}
		printf("NULL \n \n");
	}

}

int pop()
{
	struct stack *current;
	current=top;
	if (current->next == NULL)// only one node
	{
		top=NULL;
		free(current);
		return 0;
	}
	else
	{
		top=current->next;
		free(current);
		return 0;
	}

}

main()
{
	int op, value;
	while(1)
	{
		printf("Enter the option: \t 1. push \t 2.pop \t 3. exit" );
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				printf("Enter the value to push into the stack:");
				scanf("%d",&value);
				push(value);
				display();
				break;
				case 2:
					pop();
					display();
					break;
					case 3:
						exit(0);
		}
	}
}
