#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20

struct stack
{
    int top;
    char a[MAXSIZE];
      
};

void push(stack *s,int value)
{
    if(s->top<(MAXSIZE-1))
    {
        s->top++;
        s->a[s->top]=value;
    }
    
    else
        printf("Stack full");
}

//identifies ch as operand, operator or parenthesis
int charIs(char ch)
{
    if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^'))
        //is operator
        return 0;
        
    else if(ch=='(')
        //is (
        return 1;
    
    else if(ch==')')
        //is )
        return 2;
        
    else //is operand
        return 3;
}

char pop(stack *s)
{
    if(s->top>=0)
    {
        s->top--;
        return s->a[s->top+1];
    }
}

int priority(char ch)
{
    if(ch=='^')
        return 6;
        
    else if((ch=='*')||(ch=='/'))
        return 5;
     
     else if((ch=='+')||(ch=='-'))
        return 4;
        
     else
        return 0;
}

int main(void)
{
    stack operators;
    operators.top=-1;
    
    char ch,element;
    int chIs;
    
    while((ch=getchar())!='\n')
    {
        
        chIs=charIs(ch);
        
        //printf("ch:%c chIs:%d\n",ch,chIs);
        
       
        //ch is operand
        if(chIs==3)
            printf("%c",ch);
        
        //ch is (
        else if(chIs==1)
            push(&operators,ch);
         
        //ch is )
        else if(chIs==2)
        {
            while((element=pop(&operators))!='(')
                printf("%c",element);
        }
        //if ch is operand       
        else
        {
            while((operators.top>=0)&&(priority(operators.a[operators.top])>=priority(ch)))
            {
                element=pop(&operators);
                printf("%c",element);
            }
            
            push(&operators,ch);
        }
        
        
    }
    
    //stack not empty
    while(operators.top>=0)
    {
        element=pop(&operators);
        printf("%c",element);
    }
    
    printf("\n");
    return 0;
}
