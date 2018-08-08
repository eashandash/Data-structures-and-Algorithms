//polynomial add
//i did it myself

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int p;
    int c;
    struct node*nptr;
};
struct node*h1=NULL,*h2=NULL,*h3=NULL;

void insert(struct node**head,int c,int p)//since inserting 2 linked list into the single function
{
    struct node*temp=malloc(sizeof(struct node));
    temp->c=c;
    temp->p=p;
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



void display(struct mode*head)
{
    struct node*thptr=head;
    while(thptr->nptr!=NULL)
    {
        printf("%dx^%d +",thptr->c,thptr->p);
        thptr=thptr->nptr;
    }
    printf("%dx^%d ",thptr->c,thptr->p);


}


void sum(struct node*head1,struct node*head2)
{
  struct node*t1=head1;
  struct node*t2=head2;

  while(t1!=NULL && t2!=NULL)
  {
      if(t1->p == t2->p)
        insert(&h3,t1->c+t2->c,t1->p);
        t1=t1->nptr;
        t2=t2->nptr;
  }
  if(t1!=NULL)
  {
      insert(&h3,t1->c,t1->p);
      t1=t1->nptr;
  }
  else if(t2!=NULL)
  {
      insert(&h3,t2->c,t2->p);
      t2=t2->nptr;
  }



}






int main()
{   int order1,order2;
    int i;
    int c;
    printf("\nenter the order of the first polynomial ");
    scanf("%d",&order1);
    for(i=0;i<=order1;i++)
    {
        printf("enter the coefficient of x^%d--",order1 -i);
        scanf("%d",&c);
        insert(&h1,c,order1-i);
    }

    display(h1);

    printf("\nenter the order of the second polynomial ");
    scanf("%d",&order2);
    for(i=0;i<=order2;i++)
    {
        printf("enter the coefficient of x^%d--",order2 -i);
        scanf("%d",&c);
        insert(&h2,c,order2-i);
    }

    display(h2);

    printf("the sum of two polynomial is \n");
    sum(h1,h2);
    display(h3);


}





