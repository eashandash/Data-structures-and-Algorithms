

#include<stdio.h>

#include<stdio.h>
struct node
{
 int data;
 struct node*next;
 };
 struct node*hptr =NULL;
 struct node*hptr1,*hptr2,*hptr3;




 void insert(struct node**hptr)
 {
  int d,x;
  do
 {
  printf("\nenter the element\n");

  scanf("%d",&x);

  struct node*temp;temp=NULL;
  temp=malloc(sizeof(struct node));
  if(*hptr==NULL)
  {
   temp->data=x;
   *hptr=temp;
   temp->next=NULL;
  }
  else
  {
   temp->data=x;
   temp->next=*hptr;
   *hptr=temp;

  }
 printf("do u wanna enter more ?\n");
 scanf("%d",&d);
 } while(d==1);
 }







 void display(struct node*t)
 {
  struct node*thptr;
  thptr=t;

  while(thptr!=NULL)
  {

   printf("-->%d    ",thptr->data);
   thptr=thptr->next;
  }
 }


 int main()
 {
   int x,i,c,d,pos;
   do
   {



    printf("enter the first sorted ll");
    insert(&hptr1);
    printf("the sorted ll is \n");
    display(hptr1);
     printf("enter the second sorted ll");
    insert(&hptr2);
    printf("the sorted ll is \n");
    display(hptr2);


    printf("do u wnna enter more \n ");
    scanf("%d",&d);
    }while(d==1);

    return(0);

    }








