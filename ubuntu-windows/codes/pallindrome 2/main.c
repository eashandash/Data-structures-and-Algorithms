

#include<stdio.h>
#include<stdlib.h>

struct node
{
	char c;
	struct node *next;
};

struct node *start=NULL,*current,*previous,*temp;

void insert_end(int value)
{
	struct node *new_node=malloc(sizeof(struct node));
	new_node->c=value;
	new_node->next=NULL;

	if(start==NULL)
	{
		start=new_node;
	}

	else
	{
		current=start;
		while(current->next!=NULL)
		{
			current=current->next;
		}

		current->next=new_node;

	}
}

void reverse()
{
	previous=start;
	current=start->next;

	start->next=NULL;

	while(current!=NULL)
	{
		temp=current->next;
		current->next=previous;
		previous=current;
		current=temp;


	}

	start=previous;

}

int main(void)
{
	char *string=(char *)malloc(sizeof(char)*30);
	scanf("%s",string);

	//printf("%s",string);
	int i;
	for(i=0;string[i]!='\0';++i)
	{
		insert_end(string[i]);
	}

	//reverse linked list
	reverse();

	//printing reversed linked list
	printf("Reversed String : ");
	current=start;
	while(current!=NULL)
	{
		printf("%c",current->c);
		current=current->next;
	}


	//check palindrome
	current=start;
	for(i=0;current!=NULL;++i)
	{
			if(current->c!=string[i])
				break;

			current=current->next;
	}

	if(current==NULL)
		printf("\nThe String %s is palindrome\n",string);

	else
		printf("\nThe String %s is NOT a palindrome\n",string);

	return 0;
}
