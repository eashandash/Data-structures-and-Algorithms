#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20

struct stack
{
    int top;
    int a[MAXSIZE];
      
};

void push(stack *s,int value)
{
    if(s->top<(MAXSIZE-1))
    {
        s->top++;
        s->a[s->top]=value;
    }
    
    else
        printf("Stack is full");
}

int pop(stack *s)
{
    if(s->top>=0)
    {
        s->top--;
        return s->a[s->top+1];
    }
}

void print(stack *s)
{
    printf("\nThe stack is\n");
    for(int i=s->top;i>=0;--i)
        printf("%d\n",s->a[i]);

}

void status(struct stack *s)
{
    if(s->top>=0)
        printf("The top most element is %d\n",s->a[s->top]);
        
    else if(s->top==-1)
        printf("The stack is empty\n");
        
    float emptyper=(MAXSIZE-s->top-1)*100.00/MAXSIZE;
    
    printf("Percentage of empty nodes %.2f\n",emptyper);
        
}

int main(void)
{
    stack s;
    s.top=-1;
    
    int value;
    
    int  choice;
    while(1)
    {
        
        printf(
            "\nEnter your choice\n"
            "1. Push element to stack\n"
            "2. Pop element from stack\n"
            "3. Print the stack\n"
            "4. View Status of stack\n"
            "5. Exit\n"
          );
          
          scanf("%d",&choice);
          
          if(choice==1)
          {
            printf("Enter value to push\n");
            scanf("%d",&value);
            
            push(&s,value);
          }
          
          else if(choice==2)
          {
            printf("Element %d removed from stack\n",pop(&s));
          }
          
          else if(choice==3)
          {
            print(&s);           
          }
          
          else if(choice==4)
          {
            status(&s);
          }
          
          else
            exit(0);
    
    }   
    
    return 0;
}
