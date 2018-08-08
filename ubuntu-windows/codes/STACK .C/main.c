

#include<stdio.h>
#include<string.h>

//---------------------------STACK--------------------------
char s[100];
const int SIZE = 100;
int top = -1;


void push(int ele)
{
	if(top==SIZE-1)
		printf("\n Stack is FULL");
	else{
	s[++top] = ele;
	}


}

void pop()
{
	if(top==-1)
		printf("\n Stack is Empty");
	else
	top--;


}

char showTop()
{
if(top==-1)
		printf("\n Stack is Empty");
	else
	return s[top];
}

//-----------------------infix to postfix--------------------------------------



int isOperand(char a)
{
	if(a>='0' && a<='9')
		return 1;

		return 0;


}


int isOperator(char a)
{
	if(a=='+' || a=='-' || a=='/' || a=='*' || a=='^')
		return 1;

		return 0;

}



int isHigherPrec(char a,char b)
{

	int aValue =0 ,bValue =0;

	switch(a)
	{
		case '+': aValue = 1; break;
		case '-': aValue = 1; break;
		case '*': aValue = 2; break;
		case '/': aValue = 2; break;
		case '^': aValue = 3; break;
	}

	switch(b)
	{
		case '+': bValue = 1; break;
		case '-': bValue = 1; break;
		case '*': bValue = 2; break;
		case '/': bValue = 2; break;
		case '^': bValue = 3; break;
	}

	if(aValue>=bValue)
		return 1;

		return 0;


}



char * infix2Postfix(char infix[200])
{
	int i ;
	char *postfix = (char*)malloc(strlen(infix)*sizeof(char));

	// char postfix[200] ;
	int k =0;

	for(i =0;i<strlen(infix);i++)
	{

		if(isOperand(infix[i]))
		{
			postfix[k++] = infix[i];
		}
		else if(isOperator(infix[i]))
		{
			while(isHigherPrec(s[top],infix[i])  &&  s[top]!='('   &&  top!=-1)
			{

				postfix[k++] = s[top];
				pop();



			}
			push(infix[i]);

		}
		else if(infix[i]=='(')
			push('(');
		else if(infix[i]==')')
		{
			while(s[top]!='(')
			{
				postfix[k++] = s[top];
				pop();
			}

			pop();
		}

	}

	while(top != -1)
	{
		postfix[k++] = s[top];
		pop();
	}


	return postfix;
}






void main()
{



	char infix[200];
	char *postfix;

	system("clear");

	printf("\n\nINFIX TO POSTFIX CONVERTER");
	printf("\n\nEnter your infix expression here : ");
	scanf(" %s",infix);



	postfix = infix2Postfix(infix);

	printf("\n\nYour postfix expressin is : %s \n\n\n\n\n\n\n\n",postfix);









}
