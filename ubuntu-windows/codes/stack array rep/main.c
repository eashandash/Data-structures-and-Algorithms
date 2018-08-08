// stack array rep

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int a[10];
    int top;
};

struct stack s;


void push(int x)
{
    if(s.top==9)
        printf("stack full hence overflow");
    else
    {
        s.top=s.top +1;
        s.a[s.top]=x;

    }
}


int pop()
{int x;
  if(s.top==-1)
  printf("stack empty , hence underflow");
  else
  {
     x=s.a[s.top];
     s.top=s.top--;
  }
  return x;

}

int main()
{

    s.top=-1;

    int i,x,j;

  do
  {
      printf("\n enter ur choice  1.insert  2.deleting\n");
      scanf("%d",&i);
switch(i)
{
    case 1 : {printf("\nenter the element to b inserted\n");
               scanf("%d",&x);
               push(x);
               for(j=0;j<=s.top;j++)

                printf("-->%d",s.a[j]);



                }
                break;
   case 2 : {
              printf("\nthe element deleted is %d\n",pop());
              for(j=0;j<=s.top;j++)

                   printf("-->%d",s.a[j]);


              }
              break;
}

printf("do u wana continue?");
scanf("%d",&i);
  }while(i==1);





  return(0);

}








