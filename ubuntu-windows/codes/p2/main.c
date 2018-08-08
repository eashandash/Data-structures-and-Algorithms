//palindrome

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
    char data;
    struct node*nptr;
};
struct node*h1=NULL;
struct node*h2=NULL;


void insert1(struct node*head,char x)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->nptr=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->nptr=head;
        head=temp;
    }
}

void insert2(struct node *head,char x)
{
  struct node*temp=malloc(sizeof(struct node));
  temp->data=x;
  temp->nptr=NULL;
  if(head==NULL)
  {
      head=temp;
  }
  else
  {
      struct node*thptr =head;
      while(thptr->nptr!=NULL)
      {
          thptr=thptr->nptr;
      }
      temp->nptr=NULL;
          thptr->nptr=temp;
  }
}

void rev(struct node*head1,struct node*head2)
{
    struct node*thptr=head1;
    while(thptr!=NULL)
    {
        insert2(head2,thptr->data);
        thptr=thptr->nptr;
    }
}
void display(struct node*head)
{
    struct node*thptr=head;
    while(thptr!=NULL)
    {
        printf("%d",thptr->data);
        thptr=thptr->nptr;
    }
}





int main()
{   char a[10];
    int i;
    printf("enter the string .\n");
    scanf("%s",&a);
    int l=strlen(a);
    for(i=0;i<l;i++)
    {
        insert1(h1,a[i]);
    }
    rev(h1,h2);
    printf("the rev string is");
    display(h2);














return 0;
}


