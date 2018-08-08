#include <stdio.h>
#include <stdlib.h>

int a[200];
const int size;
int top=-1;

void push(int x)
{
    if(top==size -1)
        printf("overflow,stack is full");
    else
    {
        top++;
        a[top]=x;
    }

}
void pop()
{
    if(top==-1)
    printf("underflow,stack is empty");
    else
        {

        top--;
        }


}
void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
     printf("%d",a[i]) ;
    }

}



