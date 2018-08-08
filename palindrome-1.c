#include<stdio.h>
#include<stdlib.h>

struct node
{
	char a;
	struct node *next;
};

typedef struct node n;

n *head = NULL; //first linked list header
n *head2= NULL;  //second linked list header
n *temp = NULL;
n *temp2 = NULL;

//functoion to insert characters in linked list
void insert(char c)
{
	temp = malloc(sizeof(n));
	temp->a=c;
	temp->next = NULL;

	if(head == NULL)
		head = temp;
	else
	{
		temp2=head;
		while(temp2->next!=NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp;
	}


}

//function to reverse linked list
void rev(n *head)
{
	if(head == NULL)
		return;
	else
		rev(head->next);

	temp = malloc(sizeof(n));
	temp->a=head->a;
	temp->next = NULL;
	if(head2 == NULL)
		head2 = temp;
	else
	{
		temp2 = head2;
		while(temp2->next!=NULL)
			temp2 = temp2->next;
		temp2->next = temp;
	}

}

//function to compare two linked list
int compare(void)
{
	int flag=1;
	temp = head;
	temp2 = head2;
	while(temp!=NULL)
	{
		if(temp->a != temp2->a)
		{
			flag =0;
			break;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	return flag;
}

void display(struct node*head)
{
    struct node*thptr=head;

    while(thptr!=NULL)
    {
        printf("%c",thptr->a);
        thptr=thptr->next;


    }
}


int main(void)
{
 	char s1[50];
 	int i=0;
 	printf("Enter a string: ");
 	scanf("%s",s1);

 	//storing in linked list
 	while(s1[i]!='\0')
 	{
 		char c = s1[i];
 		insert(c);
 		i++;
 	}

 	rev(head);
    display(head);
    printf("\n");
    display(head2);
 	//comparing the original and reversed strings
 	int a = compare();
 	if(a == 1)
 	printf("Awesome bro, you found a string that is a palindrome!!\n");
 	else
 	printf("Sorry bro, but the string is not a palindrome.\n");
 	return 0;
}
