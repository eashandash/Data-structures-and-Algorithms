

#include<stdio.h>
struct node
{
 int data;
 struct node*next;
 };
 struct node*hptr =NULL;

 void insert(int x)
 {
  struct node*temp=malloc(sizeof(struct node));
  if(hptr==NULL)
  {
   temp->data=x;
   hptr=temp;
   temp->next=NULL;
  }
  else
  {
   temp->data=x;
   temp->next=hptr;
   hptr=temp;
  }
 }

 void reverse(struct node*temp)
 {
  if(temp==NULL)
   return ;

  reverse(temp->next);

  printf("--->%d",temp->data);

 }










 void display()
 {
  struct node*thptr;
  thptr=hptr;

  while(thptr!=NULL)
  {

   printf("-->%d",thptr->data);
   thptr=thptr->next;
  }
 }


 int main()
 {
   int x,i,c,d,pos;
   do
   {
    printf("MENU 1.INSERT \n 2.reverse ");
    scanf("%d",&c);

    switch(c)
    {
      case 1 : {
                 printf("\n enter the element \n");
                 scanf("%d",&x);
                 insert(x);
                 display();
                }break;

      case 2 :{
                printf("reversing the LL ");
                reverse(hptr);

                }break;
     }

    printf("do u wnna enter more \n ");
    scanf("%d",&d);
    }while(d==1);

    return(0);

    }









