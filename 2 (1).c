#include<stdio.h>

struct node
{
 int data;
 struct node*l;
 struct node*r;
 };
 
 struct node*root=NULL;
 struct node*s,*p;
 
 struct node* insert(struct node*root,int x)
 {
   struct node*temp=malloc(sizeof(struct node));
   temp->data=x;
   temp->l=NULL;
   temp->r=NULL;
    
   if(root==NULL)
    root=temp;
   
   else
   {
     if(root->data>x)
      root->l=insert(root->l,x);
     
     else if(root->data<x)
      root->r=insert(root->r,x);
   }   
   
   
   return root;
   
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
  
  
  void inorder(struct node*root)
  { 
   if(root==NULL)
   return; 
   
   inorder(root->l);
   printf("-->%d",root->data);
   inorder(root->r);
   
  }
  
  struct node* succes(struct node*root,int k)
  {
   struct node*successor=NULL;
   struct node*current =root;
   if(!root)
   {
    printf("empty root");
    return ;
   }
   while(current->data!=k)
   {
   
   if(current->data >k)
   {
    successor=current;
    current=current->l;
   }
   else
   current=current->r;
   
  }
  
  if(current && current->r)
  {
   successor=min(current->r);
   }
   return successor;
   
  } 
  
  struct node* pred(struct node*root,int k)
  {
   struct node*pre=NULL;
   struct node*current =root;
   if(!root)
   {
    printf("empty root");
    return ;
   }
   while(current->data!=k)
   {
   
   if(current->data <k)
   {
    pre=current;
    current=current->r;
   }
   else
   current=current->l;
   
  }
  
  if(current && current->l)
  {
   pre=max(current->l);
   }
   return pre;
   
  } 
  
  
  int maxDepth(struct node* root) 
{
   if (root==NULL) 
       return 0;
   else
   {
       
       int lDepth = maxDepth(root->l);
       int rDepth = maxDepth(root->r);
 
      
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 


struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->l = deleteNode(root->l, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->r = deleteNode(root->r, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->l == NULL)
        {
            struct node *temp = root->r;
            free(root);
            return temp;
        }
        else if (root->r == NULL)
        {
            struct node *temp = root->l;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = min(root->r);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->r = deleteNode(root->r, temp->data);
    }
    return root;
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
           s=succes(root,a);
           printf("-->%d",s->data);
           }break;    
       
  case 6:{ printf("enter the element ,whose predecessor u want\n ");
           scanf("%d",&b);  
           p=pred(root,b);
           printf("-->%d",p->data);
           }break; 
           
  case 7:{ h=maxDepth(root);
           printf("%d",h);}
          break;
          
   case 8:{
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
    
   
   
   
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
     
