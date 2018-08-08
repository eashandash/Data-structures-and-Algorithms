//BST IMPLEMENTATION


#include<stdio.h>

struct node
{
	int data;
	struct node*l,*r;
};

struct node*root =NULL;
struct node*p,*s;

struct node*insert(struct node*root,int x)
{
	struct node*temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->l=NULL;
	temp->r=NULL;

	if(root==NULL)
		root=temp;
	else
	{
		if(x<root->data)
		{
			root->l=insert(root->l,x);
		}
		else if(x>root->data)
		{
			root->r=insert(root->r,x);
		}
	}

	return root;
}

struct node*min(struct node*root)
{
	while(root->l!=NULL)
	{
		root=root->l;
	}
	printf("the min element is %d",root->data);
	return root;

}

struct node*max(struct node*root)
{
	while(root->r!=NULL)
	{
		root=root->r;
	}
	printf("the max element is %d",root->data);
	return root;
}


void inorder(struct node*root)
{
	if(root==NULL)
		return;

	else
	{
		inorder(root->l);
		printf("-->%d",root->data);
		inorder(root->r);
	}
}

void preorder(struct node*root)
{
	if(root==NULL)
		return;

	else
	{
		printf("-->%d",root->data);
		preorder(root->l);
		preorder(root->r);
	}
}

struct node*suc(struct node*root,int k)
{
	struct node*current=root;
	struct node*suc=NULL;

	if(!root)
	{
		printf("empty tree");
		return;
	}
	else if(current->r!=NULL)
	{
		suc=min(current->r);
	}
	else
	{
		while(current->data!=k)
		{
			if(current->data>k)
			{
				suc=current;
				current=current->l;

			}
			else
				current=current->r;

		}
	}
		return suc;
}



  int main()
  {
   int c,d,i,a,b,h;
   do
   {
   printf("menu --1.insert \n2.display(inorder) \n3.max element \n4.min element\n 5.succesor \n 6.predecessor \n 7.hight \n 8.delete\n");
   scanf("%d",&c);
   switch(c)
   {

   case 1 : {printf("enter value to be inserted\n ");
              scanf("%d",&d);
              root=insert(root,d);
              inorder(root);}
              break;
  case 2 :  {inorder(root);}
            break;

  case 3:  {
             max(root);
             }break;
  case 4: {
              min(root);
              }break;

  case 5:{ printf("enter the element ,whose succesor u want\n ");
           scanf("%d",&a);
           s=suc(root,a);
           printf("-->%d",s->data);
           }break;

  //case 6:{ printf("enter the element ,whose predecessor u want\n ");
           scanf("%d",&b);
           p=pred(root,b);
           printf("-->%d",p->data);
           }break;

  //case 7:{ h=maxDepth(root);
           //printf("%d",h);}
         // break;

   //case 8:{
            printf("enter the node to be deleted\n");
            scanf("%d",&d);
            deleteNode(root,d);
            inorder(root);
            }break;



  }
  printf("do u wanna enter more ?\n");
  scanf("%d",&i);
  }while(i==1);






  return (0);

  }



