//doubly linkedlist circular queue

#include <stdio.h>
#include <stdlib.h>
int count;

struct node
{
    int data;
    struct node*next;
    struct node*pre;
};
struct node*first=NULL;
struct node*last=NULL;

void insert(int x)
{
    struct node*temp=malloc(sizeof(struct node));
    if(first==NULL && last==NULL)
    {
        first=temp;
        last=temp;
        temp->data=x;
        first->next=NULL;
        first->pre=NULL;
        last->next=NULL;
        last->pre=NULL;
    }
    else
    {
        temp->data=x;
        last->next=temp;
        temp->pre=last;
        last=temp;
        last->next=first;
        first->pre=last;
        count++;
    }
}

int del()
{   int x;
    if(first==NULL && last==NULL)
    printf("\n underflow\n");
    else
    {
        struct node*temp;
        temp=first;
        x=temp->data;
        first=temp->next;

    }
    count--;

   return x;
}

void display()
{
    struct node*thptr;
     int i;
    for(thptr=first,i=0;thptr<=last,i<=count;i++)
    {
        printf("-->%d",thptr->data);
        thptr=thptr->next;
    }
}


int main()
{
    int n,x,c;
    do
    {
        printf("MENU\n 1.insert\n2.delete\n3.display\n");
        scanf("%d",&n);
        switch(n)
        {
         case 1:{printf("\nenter the element to be inserted\n");
                 scanf("%d",&x);
                 insert(x);
                 display();}break;
         case 2:
            {
                del();
                display();
            }break;
         case 3: {
                   display();
                   }break;
        }

       printf("\ndo u wanna continue?\n ");
       scanf("%d",&c);
    }while(c==1);

return(0);
}
