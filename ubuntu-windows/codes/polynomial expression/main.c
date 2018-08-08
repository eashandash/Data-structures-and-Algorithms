#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe;
    int po;
    struct node*next;

};

struct node*hptr=NULL;

void insert(int coe,int po)
{
    struct node*temp=malloc(sizeof(struct node));
    if(hptr==NULL)
    {
        temp->coe=coe;
        temp->po=po;
        hptr=temp;
    }
    else
    {
        temp->coe=coe;
        temp->po=po;
        temp->next=hptr;
        hptr=temp;
    }
}

int val(int x)
{    int c=0;
    struct node*thptr=hptr;
    while(thptr!=NULL)
    {
      c=c+((thptr->coe)*(x^thptr->po));
      thptr=thptr->next;
    }
    return c;
}

int main()
{   int n,y,z,x,i;
    printf("POLYNOMIAL EVALUATION\n");
    printf("\n enter how many terms ?");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\n enter the coeff and power :\n");
        scanf("%d%d",&y,&z);
        insert(y,z);
    }
    printf("\n enter the value of x :");
    scanf("%d",&x);
    printf("\n the value is %d",val(x));

    return(0);
}
