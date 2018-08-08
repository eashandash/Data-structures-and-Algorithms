//circulat queue using one var

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*nptr;
};
struct node*last=NULL;

void insertlast(int x)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->nptr=NULL;

    if(last==NULL)
    {
        last=temp;
        last->nptr=last;

    }
    else
    {
        temp->nptr=last->nptr;
        last->nptr=temp;
        last=temp;
    }
}

void insertbeg(int x)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->nptr=NULL;

    if(last==NULL)
    {
        last=temp;
        last->nptr=last;

    }

    else
    {

        temp->nptr=last->nptr;
        last->nptr=temp;
    }
}


void display()
{
     struct node*h=last->nptr;
    struct node*thptr=h;
    while(thptr!=last)
    {
        printf("--->%d",thptr->data);
        thptr=thptr->nptr;

    }
    printf("--->%d",thptr->data);
}

int main()
{
    int i,c,d;
    do
    {
    printf("menu 1.insertbeg  2.insertend  3.delbeg  3.delend\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:{printf("enter the value to b inserted  -\n");
               scanf("%d",&d);
               insertbeg(d);
               display();}
               break;
         case 2:  { printf("enter the value to b inserted  -\n");
               scanf("%d",&d);
               insertlast(d);
               display();}
               break;
    }
    printf("do u wanna enter more?");
    scanf("%d",&i);
    }while(i==1);


    return(0);



}

