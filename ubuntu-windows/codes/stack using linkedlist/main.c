#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*nptr;
};
struct node*hptr=NULL;

void insert(int x)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->nptr=hptr;
    hptr=temp;

}

int del()
{    if(hptr==NULL)
      printf("\nstack underflow\n");
      else
{


    struct node*temp;
    temp=hptr;
    printf("\nthe deleted element is %d\n",temp->data);
    hptr=temp->nptr;
}
}

void search(int z)
{   int flag=0;
    struct node*thptr=hptr;
    while(thptr!=NULL)
    {
        if(thptr->data==z)
            flag=1;

        thptr=thptr->nptr;
    }
    if(flag==1)
        printf("element found");
    else
        printf("not found");
}
void display()
{
   struct node*thptr=hptr;
   while(thptr!=NULL)
   {
       printf("--->%d",thptr->data);
       thptr=thptr->nptr;
   }
}


int main()
{
    int i,n,c,x,z;
    do
    {
      printf("\nMENU--1.insert \n2.delete\n3.search\n");
      scanf("%d",&n);

     switch(n)
     {
      case 1:{printf("enter the element");
              scanf("%d",&x);
              insert(x);
              display();
              }break;
      case 2:{del();
              display();}break;
      case 3: {printf("enter the element to be searched for");
                scanf("%d",&z);
                search(z);} break;

     }
     printf("\ndo u wish to continue?\n");
     scanf("%d",&c);
    }while(c==1);

    return(0);
}


