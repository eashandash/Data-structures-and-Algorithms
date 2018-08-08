#include<stdio.h>

struct node
{
	int data;
	struct node*l,*r;

};

struct node*root=NULL;
struct node*s,*p;

struct node*insert(struct node*root,int k)
{
	struct node*temp=malloc(sizeof(struct node));
	temp->data=k;
	temp->r=NULL;
	temp->l=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		if(root->data>k)
			root->l=insert(root->l,k);
		else if(root->data<k)
		root->r=insert(root->r,k);
	}
	return root;
}


int maxd(struct node*root)
{
	if(root==NULL)
	return 0;

 int ld=maxd(root->l);
 int rd=maxd(root->r);
 if(ld>rd)
 	return (ld+1);
else
	return(rd+1);

}


  struct node* min(struct node *root)
{
	while(root->l != NULL)
	{
		root=root->l;
	}
	printf("minimum is %d", root->data);
	return root;
}

struct node* max(struct node *root)
{
	while(root->r != NULL)
	{
		root=root->r;
	}
	printf("maximum is %d", root->data);
	return root;
}




struct node*su(struct node*root,int k)
{
	struct node*suc=NULL;
	struct node*cur=root;

	if(!root)
	{
		printf("empty tree");
		return;
	}
	while(cur->data!=k)
	{
		if(cur->data>k)
		{
			suc=cur;
			cur=cur->l;
		}
		else
			cur=cur->r;
	}
	if(cur&&cur->r)
	{
		suc=min(cur->r);
	}
	return suc;

}

struct node*pr(struct node*root,int k)
{
  struct node*pre=NULL;
  struct node*cur=root;

	if(!root)
	{
		printf("empty tree");
		return;
	}
	while(cur->data!=k)
	{
		if(cur->data<k)
		{
			pre=cur;
			cur=cur->r;
		}
		else
			cur=cur->l;
	}
	if(cur&&cur->l)
	{
		pre=max(cur->l);
	}
	return pre;
}

  
  
  void inorder(struct node*root)
  { 
   if(root==NULL)
   return; 
   
   inorder(root->l);
   printf("-->%d",root->data);
   inorder(root->r);
   
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
           s=su(root,a);
           printf("-->%d",s->data);
           }break;    
       
  case 6:{ printf("enter the element ,whose predecessor u want\n ");
           scanf("%d",&b);  
           p=pr(root,b);
           printf("-->%d",p->data);
           }break; 
           
  case 7:{ h=maxd(root);
           printf("%d",h);}
          break;

   case 8:{
   	        printf("enter the element to be deleted\n");
   	        scanf("%d",&d);
   	        deleteNode(root,d);
   	        inorder(root);}
   	        break;
   }       
          
   
            
  
  }
  printf("do u wanna enter more ?\n");
  scanf("%d",&i);
  }while(i==1);
  
  
  
  
  
  
  return (0);
  
  }




