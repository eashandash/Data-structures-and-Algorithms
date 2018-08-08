//reversing a linked list
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

    if(hptr==NULL)
    {
     hptr=temp;
     temp->data=x;
     temp->nptr=NULL;
    }
    else
    {
        temp->data=x;
      temp->nptr=hptr;
      hptr=temp;
    }
}
int del()
{
    int x;
    struct node*thptr;
    if(hptr==NULL)
    printf("empty list");

    else
    {
      thptr=hptr;
      x=thptr->data;
      hptr=thptr->nptr;
    }

    return x;

}

struct node*rev(struct node*hello)
{
 if(hello!==NULL)
 return;

 rev(hello->nptr);

 printf("-->%d",hello->data);
}
 void display(hptr)
 {
     struct node*thptr;
        thptr=hptr;
     while(thptr!=NULL)
     {
         printf("-->%d",thptr->data);
         thptr=thptr->nptr;
     }
 }

int main()
{
    int x,c,n;
    do
    {
        printf("\n menu \n1.insert 2.delete  3.rev");
        scanf("%d",&n);

        switch(n)
        {
        case 1:
            {
                printf("enter the value to be inserted");
                scanf("%d",&x);
                insert(x);
                display(hptr);

            }break;
          case 2: {
                   del();
                   display(hptr);
                   }break;
          case 3: {
                   struct node*t=rev(hptr);
                   display(t);}break;

        }
        printf("\n do u wanna enter more?\n");
        scanf("%d",&c);
      }while(c==1);
      return(0);
}



