#include <stdio.h>
#include <stdlib.h>

float a[200];
int top=-1;
const int SIZE=200;

void push(float x)
         {
           if(top==SIZE-1)
            printf("overflow");
           else
           {
               top++;
               a[top]=x;
           }
         }
  float pop()
  {float x;
      if(top==-1)
        printf("underflow");
      else
      {
          x=a[top];
          top--;
      }
      return x;
  }

  int isint(char a)
  {
      if(a>='0' && a<='9')
        return 1;

      else
        return 0;
  }

  int isoperator(char a)
  {
    if(a=='+' || a=='-'||a=='*'||a=='/'||a=='^')
        return 1;

    else
        return 0;
  }

  float op(float a,float b,char c)
  {
      if(c=='+')
        return a+b;

      else if(c=='-')
        return a-b;

      else if(c=='*')
        return a*b;

      else if(c=='/')
        return a/b;
  }



  int main()
  {
   char postfix[200];
   int i;
   float num1,num2;
   float res=0;
   printf("\nenter the postfix exp\n");
   scanf("%s",postfix);

   for(i=0;i<=strlen(postfix);i++)
   {
       if(isint(postfix[i]))
       {
           push(postfix[i]-48);
       }
       else if(isoperator(postfix[i]))
       {
           res =0;
           num2=pop();
           num1=pop();
           res=op(num1,num2,postfix[i]);
           push(res);
       }

   }
   printf("result is %f",pop());

   return(0);


  }
