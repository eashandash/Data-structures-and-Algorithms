#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*nptr;

};
struct node *hptr =NULL;

void insert(int x,int pos)
{
    struct node*temp=malloc(sizeof(struct node));
    struct node*thptr;
    int i=1;
    if(pos==1)
    {

    temp->data=x;
    temp->nptr=hptr;
    hptr=temp;
    }
    else{
        temp->data=x;
        thptr=hptr;
        while(thptr!=NULL && i<pos-1)
        {
            thptr=thptr->nptr;
            i++;
        }
        temp->nptr=thptr->nptr;
        thptr->nptr=temp;


    }
}
void del(int pos)
{

    struct node*thptr,*temp;
    temp=hptr;
    int i;
    if(pos==1)
    {
     hptr=temp->nptr;

    }
    else
    { for(i=1;i<pos;i++)
    {
        thptr=temp;
        temp=temp->nptr;
    }
    thptr->nptr=temp->nptr;
    }



}

void display()
{
    struct node*thptr=hptr;
    while(thptr!=NULL)
    {
        printf("--->%d",thptr->data);
        thptr=thptr->nptr;
    }

}

int lsearch(int x)
{
    int flag=0;
    struct node*thptr=hptr;
    while(thptr!=NULL)
    {
        if(thptr->data==x)
            flag =1;

        thptr=thptr->nptr;

    }
    if(flag==1)
    printf("\n element is found");
     else
       printf("\n element is not found");

}

int main()
{
    int d,i,c,x,pos,p;
    do
    {
        printf("menu  1.insert 2.searching  3.delete");
        scanf("%d",&c);

    switch(c)
    {
        case 1:
               {
                 printf("enter element and pos");
                 scanf("%d%d",&x,&pos) ;
                 insert(x,pos);
                 display();
               }
               break;
         case 2: {
                    printf("enter element to b searched for");
                    scanf("%d",&i);
                    lsearch(i);
                    display();


                }
                break;
           case 3: {
                     printf("enter the position to be deleted ");
                     scanf("%d",&p);
                     del(p);
                     display();
                     }
                     break;


    }
    printf("do u wanna continue");
    scanf("%d",&d);


}while(d==1);
return(0);
}





