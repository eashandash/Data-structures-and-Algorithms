// iterative binary search tree

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root=NULL, *new_node,*current;

void insert(value)
{
	new_node=malloc(sizeof(struct node));
	new_node->data=value;
	new_node->left=NULL;
	new_node->right=NULL;
	
	if(root==NULL)
	{
		root=new_node;
	}
	else
	{
		current=root;
		while(1)
		{
			if (new_node->data < current->data) // insert at left
			{
				if (current->left == NULL)
				{
					current->left=new_node;
					break;
				}
				current=current->left;	
									
			}
			else if(new_node->data > current->data)// insert at right
			{
				if(current->right == NULL)
				{
					current->right=new_node;
					break;
				}
				current=current->right;
				
			}
		}
	}
	
}

int search(value)
{
	current=root;
	while(current != NULL)
	{
		if(value < current->data) //search in left
		{
			current=current->left;
		
		}
		else if (value > current->data)// search in right
		{
			current=current->right;
		}
		else if (value == current->data) //matched
		{
			//	printf("%d",current->data);
			return (current->data);	
		}
		
	}
	
}

findmin(struct node *root)
{
	while(root->left != NULL)
	{
		root=root->left;
	}
	printf("minimum is %d", root->data);
}

findmax(struct node *root)
{
	while(root->right != NULL)
	{
		root=root->right;
	}
	printf("maximum is %d", root->data);
}

void display(struct node *root) // implement recursive inoder 
{
	if(root != NULL)
	{
		display(root->left);
		printf("%d->",root->data);
		display(root->right);
		
	}
	
}

void preorder(struct node *root) // implement recursive inoder 
{
	if(root != NULL)
	{
		printf("%d->",root->data);
		preorder(root->left);
		preorder(root->right);
		
	}
	
}

void postorder(struct node *root) // implement recursive inoder 
{
	if(root != NULL)
	{
		
		postorder(root->left);
		postorder(root->right);
		printf("%d->",root->data);
		
	}
	
}


main()
{
	int op, value,i;
	while(1)
	{
		printf("\n Enter your choice:\t 1. Insert \t 2. Search \t. 3.Traversal \t 4. Find Min and Max \t 5. Exit ");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				printf("Enter the value");
				scanf("%d",&value);
				insert(value);
				display(root);
				break;
				
				case 2:
					printf("Enter the number to search");
					scanf("%d",&value);
					i=search(value);
					if(i)
						printf("element found %d",i);
					else
						printf("element not found");
					break;
					case 3:
						printf("Inorder:");
						display(root);
						printf("\n");
						printf("preorder:");
						preorder(root);
						printf("\n");
						printf("postorder:");
						postorder(root);
						printf("\n");
						break;
						case 4:
							findmin(root);
							findmax(root);
							case 5:
							exit(0);
		}
	}
}
