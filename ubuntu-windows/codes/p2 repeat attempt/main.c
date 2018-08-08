//pallindrome attempt 2

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char c;
    struct node*nptr;
};
struct node*h1=NULL;
struct node*h2=NULL;
struct node*h3=NULL;



void insert1(struct node**head,char c)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->c=c;
    temp->nptr=NULL;

    if(*head==NULL)
    {
        *head=temp;
    }

    else
    {
        temp->nptr=*head;
        *head=temp;
    }

}

void insert2(struct node**head,char c)
{
  struct node*temp=malloc(sizeof(struct node));
  struct node*thptr;
  thptr=*head;
    temp->c=c;
    temp->nptr=NULL;

    if(*head==NULL)
    {
        *head=temp;
    }

    else
    {
       while(thptr->nptr!=NULL)
       {
           thptr=thptr->nptr;
       }
       temp->nptr=NULL;
       thptr->nptr=temp;

    }

}

void display(struct node*head)
{

    struct node*thptr=head;
    while(thptr!=NULL)
    {
        printf("%c",thptr->c);
        thptr=thptr->nptr;
    }
    printf("\n");

}

void rev(struct node*head1,struct node*head2)
{
    struct node*thptr=head1;
    while(thptr!=NULL)
    {
        insert2(&head2,head1->c);
        thptr=thptr->nptr;

    }



}

 int main()
 {
     char a[10];
    int i,flag=0;
    printf("enter the string .\n");
    scanf("%s",&a);
    int l=strlen(a);
    for(i=0;i<l;i++)
    {
        insert1(&h1,a[i]);
    }
    for(i=0;i<l;i++)
    {
        insert2(&h3,a[i]);
    }
    printf("first string\n");
    display(h1);
    rev(h1,h2);
    printf("second string\n");
    display(h2);

    struct node*t1,*t2;
    t1=h3;t2=h2;
    while(t1!=NULL && t2!=NULL)
    {
      if(t1->c!=t2->c)
      {
      flag=1;
      printf("hello");
      break;
      }
      t1=t1->nptr;
      t2=t2->nptr;
    }
    if(flag)
        printf("not a pallindrome");
    else
    printf("a pallindrome");





    return 0;
 }


