


#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start1=NULL,*start2=NULL,*start3=NULL,*start=NULL;
struct node *current1,*current2,*current;

void insert_begin(int value,int linked_list)
{
	struct node *new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;

	if(linked_list==1)
		start=start1;

	else if(linked_list==2)
		start=start2;

	else if(linked_list==3)
		start=start3;

	if(start==NULL)
		start=new_node;

	else
	{
		new_node->next=start;
		start=new_node;
	}

	if(linked_list==1)
		start1=start;

	else if(linked_list==2)
		start2=start;

	else if(linked_list==3)
		start3=start;
}

void addpoly()
{
	current1=start1;
	current2=start2;

	int temp1,temp2,value;
	while(!((current1==NULL)&&(current2==NULL)))
	{
		temp1=0;
		temp2=0;

		if(current1!=NULL)
			temp1=current1->data;

		if(current2!=NULL)
			temp2=current2->data;

		value=temp1+temp2;
		insert_begin(value,3);

		if(current1!=NULL)
			current1=current1->next;

		if(current2!=NULL)
			current2=current2->next;


	}
}

int main()
{
	int order1;
	scanf("%d",&order1);

	int i,coef;
	for(i=0;i<=order1;++i)
	{
		printf("Enter coef of x^%d : ",order1-i);
		scanf("%d",&coef);
		insert_begin(coef,1);
	}

	int order2;
	scanf("%d",&order2);

	for(i=0;i<=order2;++i)
	{
		printf("Enter coef of x^%d : ",order2-i);
		scanf("%d",&coef);
		insert_begin(coef,2);
	}


	current1=start1;
	while(current1!=NULL)
	{
		printf("%d ",current1->data);
		current1=current1->next;
	}

	printf("\n");
	current2=start2;
	while(current2!=NULL)
	{
		printf("%d ",current2->data);
		current2=current2->next;
	}

	addpoly();

	printf("\nResult : ");


	int order;
	if(order2>=order1)
		order=order2;

	else
		order=order1;

	current=start3;
	for(i=0;current!=NULL;++i)
	{
		printf("%d x^%d ",current->data,order-i);
		current=current->next;

		if(current!=NULL)
			printf("+ ");
	}


	printf("\n");

	return 0;
}

