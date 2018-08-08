#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
    char c;
    struct node*nptr;
};
struct node*head=NULL;
struct node*h2=NULL;

void insert(char x)
{
    struct node*temp=malloc(sizeof(struct node));
    struct node*thptr;
    temp->c=x;
    temp->nptr=NULL;

    if(head==NULL)
       head=temp;

    else
    {
        thptr=head;
        while(thptr->nptr!=NULL)
        {
            thptr=thptr->nptr;
        }

        thptr->nptr=temp;

    }

}

void display(struct node*head)
{
    struct node*thptr=head;
    while(thptr!=NULL)
    {
        printf("%c",thptr->c);
        thptr=thptr->nptr;
    }
}

int main()
{
    int d,i;
    char x;
    char a[10];
    printf("enter the string\n");
    scanf("%s",&a);
    for(i=0;i<strlen(a);i++)
    {
        x=a[i];
        insert(x);
    }
    printf("the string enterd is : ");
    display(head);
}
