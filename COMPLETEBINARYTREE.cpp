#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}*root=NULL,*temp;

struct node* new_node(int x)
{

	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=x;
	n->lchild=NULL;
	n->rchild=NULL;
	return(n);
}

int count(struct node *n)
{
	int c=1;
	if(n==NULL)
	  return 0;
    else 
    {
    	c =c + count(n->lchild);
    c =c + count(n->rchild);
    	return c;
	}
}

int isfull(struct node *r)
{
	if(r==NULL)
      return 0;
    else if(count(r->lchild)==count(r->rchild))
       return 1;
    else 
       return 0;
}

void insert(struct node *r,struct node *t)
{
	if(r==NULL)
	{
		root=t;
	}
	
	else if(r->lchild==NULL)
	{
	
	  r->lchild=t;
}
	else if(r->rchild==NULL)
	  r->rchild=t;
	else
	{printf("i am in\n");
		if(isfull(r))
		{
			insert(r->lchild,t);
		}
		else if(!isfull(r->lchild))
		{
			insert(r->lchild,t);
		}
		else
		{
			insert(r->rchild,t);
		}
		
	}
}

void inorder(struct node *root)   
{
	if (root!=NULL)
	{//	printf("hello ji\n");
		inorder(root->lchild);
		printf("%d->",root->data);
		inorder(root->rchild);
	}
}



void preorder(struct node *root)
{
	if (root!=NULL)
	{
		printf("%d->",root->data);
		preorder(root->lchild);
		
		preorder(root->rchild);
	}
}

void postorder(struct node *root)
{
	if (root!=NULL)
	{
		
		postorder(root->lchild);
		
		postorder(root->rchild);
		printf("%d->",root->data);
	}
}

int main(void)
{
	int x,ch;
	while(1)
	{
		printf("\n1.insert\n2.postorder\n3.preorder\n4.inorder\n5.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the value to be inserted in the tree\n");
			       scanf("%d",&x);
			       temp=new_node(x);
			       insert(root,temp);
			       break;
			case 2:postorder(root);
			        break;
			case 3:preorder(root);
			       break;
			case 4:inorder(root);
			    break;
		    case 5:exit(1);
		    default:printf("take care ....look at the menu properly\n");
			
		}
	}
	return(0);
}
