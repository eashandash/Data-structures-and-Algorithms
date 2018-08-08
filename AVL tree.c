
//AVL TREE IMPLIMENTATION

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{  int data;
   struct node *left,*right;
   int ht;
}node;


node*insert(node *,int x);
node*Delete(node *,int x);
void preorder(node *);
void inorder(node *);
int height( node *);
node*rotateright(node *);
node*rotateleft(node *);
node*RR(node *);
node*LL(node *);
node*LR(node *);
node*RL(node *);
int BF(node *);
void main()
{
    node *root=NULL;
    int x,n,i,ch;
    do
    {
        printf("\nwelcome to AVL TREE ! \n");
        printf("\n1.Create \n2.Insert \n3.Delete \n4.Display \n5.Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("\nEnter no.of elements=");
                scanf("%d",&n);
                printf("\n Enter tree data=");
                root=NULL;
                for(i=0;i<n;i++)
                {
                scanf("%d",&x);
                root=insert(root,x);
                }
                break;
        case 2:printf("\nEnter a data : ");
                scanf("%d",&x);
                root=insert(root,x);
                break;
        case 3:printf("\nEnter a data : ");
                scanf("%d",&x);
                root=Delete(root,x);
                break;
        case 4:printf("\nPreorder sequence :\n");
                preorder(root);
                printf("\nInorder sequence :\n");
                inorder(root);
                break;
            }

}while(ch!=5);

}
node * insert(node *t,int x)
{
    if(t==NULL)
    {
        t=(node*)malloc(sizeof(node));
        t->data=x;
        t->left=NULL;
        t->right=NULL;
    }
    else if(x > t->data)                // insert in right subtree
        {
            t->right=insert(t->right,x);
            if(BF(t)==-2)
                if(x>t->right->data)
                    t=RR(t);
                else
                    t=RL(t);
        }
        else if(x<t->data)
            {
                t->left=insert(t->left,x);
                if(BF(t)==2)
                    if(x < t->left->data)
                        t=LL(t);
                    else
                        t=LR(t);
            }
            t->ht=height(t);
            return(t);
}

node * Delete(node *t,int x)
{       node *p;

    if(t==NULL)
    {
        return NULL;
    }
    else if(x > t->data)                // insert in right subtree
        {
         t->right=Delete(t->right,x);
         if(BF(t)==2)
                if(BF(t->left)>=0)
                    t=LL(t);
                else
                    t=LR(t);
        }
        else if(x<t->data)
                {
                    t->left=Delete(t->left,x);
                    if(BF(t)==-2)//Rebalance during windup
                        if(BF(t->right)<=0)
                            t=RR(t);
                        else
                            t=RL(t);
                }
            else
              {
                //data to be deleted is found
                  if(t->right !=NULL)
                  {  //delete its inorder succesor
                      p=t->right;
                      while(p->left != NULL)
                      p=p->left;

                      t->data=p->data;
                      t->right=Delete(t->right,p->data);
                      if(BF(t)==2)//Rebalance during windup
                        if(BF(t->left)>=0)
                            t=LL(t);
                        else
                            t=LR(t);
                   }
                  else
                   return(t->left);

              }
    t->ht=height(t);
    return(t);
}

int height(node *t)
{
    int lh,rh;
    if(t==NULL)
        return(0);
    if(t->left==NULL)
        lh=0;
    else
        lh=1+t->left->ht;
    if(t->right==NULL)
        rh=0;
    else
        rh=1+t->right->ht;
    if(lh>rh)
        return(lh);
    return(rh);
}
node * rotateright(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
node * rotateleft(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
node * RR(node *t)
{
    t=rotateleft(t);
    return(t);
}
node * LL(node *t)
{
    t=rotateright(t);
    return(t);
}
node * LR(node *t)
{
    t->left=rotateleft(t->left);
    t=rotateright(t);
    return(t);
}
node * RL(node *t)
{
    t->right=rotateright(t->right);
    t=rotateleft(t);
    return(t);
}
int BF(node *t)
{
    int lh,rh;
    if(t==NULL)
    return(0);
    if(t->left==NULL)
        lh=0;
    else
        lh=1+t->left->ht;
    if(t->right==NULL)
        rh=0;
    else
        rh=1+t->right->ht;
    return(lh-rh);
}
void preorder(node *t)
{
    if(t!=NULL)
    {
        printf(" %d(Balance factor=%d)",t->data,BF(t));
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf(" %d(Bf=%d)",t->data,BF(t));
        inorder(t->right);
    }
}


