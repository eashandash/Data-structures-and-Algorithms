#include <stdio.h>
#include <stdlib.h>

struct node
{
    int c;
    int p;
    struct node*next;
};
struct node*hptr=NULL;
struct node*hptr1=NULL,*hptr2=NULL;
struct node*hptr3=NULL;

void insert(struct node**head,int p,int c)
{
  struct node*temp=malloc(sizeof(struct node));
  temp->c=c;
  temp->p=p;
  temp->next=NULL;
  if(*head==NULL)
  {
      *head=temp;
  }
  else
  {
      temp->next=*head;
      *head=temp;
  }
}

void display(struct node*head)
{
    struct node*thptr=head;
    while(thptr!=NULL)
    {
        printf(" %dx^%d",thptr->c,thptr->p);
        thptr=thptr->next;
    }
    printf("->NULL");
}
void add(struct node*head1,struct node*head2)
{
    int p,c;
  struct node*hptr3;
  while(head1!=NULL && head2!=NULL)
  {
      if(head1->p>head2->p)
      {
        p=head1->p;
        c=head1->c;
        head1=head1->next;
      }
      else if(head1->p<head2->p)
      {

        p=head2->p;
        c=head2->c;
        head2=head2->next;
      }
      else if(head1->p==head2->p)
      {
          p=head2->p;
          c=head1->c+head2->c;
          head1=head1->next;
           head2=head2->next;

      }
      insert(&hptr3,p,c);
  }

      while(head1!=NULL)
      {
       insert(&hptr3,head1->p,head1->c);
       head1=head1->next;
      }
      while(head2!=NULL)
      {
       insert(&hptr3,head2->p,head2->c);
       head2=head2->next;
      }



  }

int main()
{
     int o1,o2,i,c;
    printf("enter the first ll order ");
    scanf("%d",&o1);
    for(i=0;i<=o1;i++)
    {
       printf("enter the coeff of x^%d",o1-i );
       scanf("%d",&c);
       insert(&hptr1,c,o1-i);

}
display(hptr1);
printf("enter the second ll order ");
    scanf("%d",&o2);
    for(i=0;i<=o2;i++)
    {
       printf("enter the coeff of x^%d",o2-i );
       scanf("%d",&c);
       insert(&hptr1,c,o2-i);

}display(hptr2);

add(hptr1,hptr2);
display(hptr3);

return (0);

}
