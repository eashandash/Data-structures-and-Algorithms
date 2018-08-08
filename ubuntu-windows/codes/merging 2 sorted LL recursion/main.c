

#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
 int data;
 struct node *next;
}Node;

Node*merge(Node *a, Node *b)
{
 Node *result=NULL;
  if(a==NULL)
    return b;
  else if(b==NULL)
     return a;
  if(a->data <= b->data)
  {
    result=a;
    result->next=merge(a->next,b);
   }
  else
  {
    result=b;
    result->next=merge(a,b->next);
   }
  return result;
 }

Node * createNode(int val)
{
Node * temp=malloc(sizeof(Node));
 if(temp)
 {
  temp->data=val;
  temp->next=NULL;
  }
  return temp;
}

void insert(Node **head, int data){
Node * newNode=createNode(data);
newNode->next=*head;
*head=newNode;
}

    void disp(Node * head){
        while(head){
            printf(" %d \t" , head->data );
            head = head->next;
        }

        printf("\n");
    }

void main()
{
Node*L1=NULL;
Node* L2=NULL;
Node * result=NULL;
int ch,ch1;
int carry=0;
do
{
printf("\nEnter 1st linked list in DESCENDING ORDER:");
scanf("%d",&ch);
insert(&L1,ch);
printf("\nDo u want to continue??");
scanf("%d",&ch1);
}while(ch1==1);
printf("\nEnter 2nd linked list in DESCENDING ORDER:");
do
{
printf("\nEnter element to be inserted=");
scanf("%d",&ch);
insert(&L2,ch);
printf("\nDo u want to continue??");
scanf("%d",&ch1);
}while(ch1==1);
printf("\nLL1:");
disp(L1);
printf("\nLL2:");
disp(L2);
printf("\nMERGED:");

L1 = merge(L1,L2);
disp(L1);
}

