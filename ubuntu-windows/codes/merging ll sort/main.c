#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node*a=NULL;
struct node*b=NULL;

struct node*merge(struct node*a,struct node*b)
{
    struct node*result;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    else if(a->data<=b->data)
    {


        result=a;
        result->next=merge(a->next,b);
    }

        else if(a->data>b->data)
        {
        result=b;
        result->next=merge(a,b->next);
        }

        return result;




};

void insert(struct node**head,int x)
{
    struct node*temp=malloc(sizeof(struct node));
    if(*head==NULL)
    {
        temp->data=x;
        *head=temp;
        temp->next=NULL;
    }
    else
    {
        temp->data=x;
        temp->next=*head;
        *head=temp;
    }


}
void display(struct node*head)
{
    struct node*thptr=head;
    while(thptr!=NULL)
    {
        printf("-->%d",thptr->data);
        thptr=thptr->next;

    }
    printf("-->NULL");
}

int main()
{

    int x,ch;
    do
    {
        printf("enter the first ll : ");
        scanf("%d",&x);
        insert(&a,x);

        printf("do u wanna enter more?");
        scanf("%d",&ch);
    }while(ch==1);
    display(a);

    do
    {
        printf("enter the second ll: ");
        scanf("%d",&x);
        insert(&b,x);
        printf("do u wanna enter more?");
        scanf("%d",&ch);
    }while(ch==1);
    display(b);


    printf("the sorted ll is ");
    struct node*temp=merge(a,b);
    display(temp);

    return 0;

}
