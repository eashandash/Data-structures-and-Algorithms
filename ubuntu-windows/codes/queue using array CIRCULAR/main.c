//array representation of queue
#include <stdio.h>
#include <stdlib.h>

int a[5];
const int size=5;
int front =-1;
int rear =-1;

void insert(int x)
{    if((rear==front&&front>0) ||(front==0 && rear==size-1))
      printf("underflow");
    else  if((rear==size-1)&&(front>0))
        {
            rear=0;
            a[rear]=x;
        }

    else if(front==-1 && rear ==-1)
    {
        front++;
        rear++;
        a[rear]=x;

    }
    else
    {
        rear++;
    a[rear]=x;

    }
}

int del()
{ int x;
  if(front==-1 && rear==-1)
        printf("underflow,stack is empty");
  else if(front==rear)
  {
      a[front]=x;
      front=-1;
      rear=-1;
  }
  else if(front==size-1)
  {
    a[front]=x;
    front=0;
  }
  else
  {
    a[front]=x;
    front++;

  }
  return x;
}
 void display()
 {
     int i,j;
     if(front>rear)
     {
        for(i=0;i<=rear;i++)
        printf("--%d",a[i]);

        for(j=front;j<=size-1;j++)
             printf("--%d",a[j]);
     }
     else
     {

     for(i=front;i<=rear;i++)
        printf("--%d",a[i]);

     }

 }
int main()
{
   int c,d,x,e;
   do
   {

   printf("menu \n 1.insert\n2.delete \n3.display\n");
   scanf("%d",&d);

   switch(d)
   {
    case 1:{ printf("enter element to b inseted \n");
            scanf("%d",&x);
            insert(x);
            display();}
            break;
    case 2: {
             del();
             display();}
             break;
     case 3: display();
             break;
   }

   printf("\ndo u wanna continue?\n");
   scanf("%d",&e);
   }while(e==1);

   return (0);
}




