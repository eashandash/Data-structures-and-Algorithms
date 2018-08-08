#include<stdio.h>
#include<string.h>
int n,top=-1;
void push(char x,char a[])
{
	top=top+1;
	a[top]=x;

}

char pop(char a[])
{
char x; 
	x=a[top];
	top--;
	return(x);
}

int priority(char symbol)
{
	if (symbol=='^')
		return(5);
	else if(symbol=='*')
		return(4);
	else if(symbol=='/')
		return(3);
	else if(symbol=='+')
		return(2);
	else if(symbol=='-');
		return(1);
        else
                return(0);
}


int main()
{
int i;
char token,element,a[30];
printf("Enter infix expression\n");
gets(a);
char s[strlen(a)];
for(i=0;i<strlen(a);i++)
{
	token=a[i];
	while(token!='\0')
	{
		if(token==40)
			push(token,s);
		
		else if(token==41)
			while((element=pop(s))!=40)
				printf("%c",element);
		else if(token >=48 && token<=122 && token!=94)
			printf("%c",token);
		
		else
		{
			while(priority(token)<priority(s[top]))
				printf("%c",pop(s));
			push(token,s);
		}
	break;
	}
}
while(top>=0)
	 printf("%c",pop(s));
	 
return(0);
}
				
				
