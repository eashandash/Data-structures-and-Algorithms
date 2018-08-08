#include <stdio.h>
#include <stdlib.h>

struct treenode
{
	int data;
	struct treenode *lsubtree;
	struct treenode *rsubtree;
};

struct treenode *start=NULL;

void createTree(struct treenode **node)
{
	//Creating a tree node
	struct treenode *temp=malloc(sizeof(struct treenode));
	printf("Enter the data to be inserted= ");
	scanf("%d",&temp->data);
	//printf("#%d#\n",temp->data);
	temp->lsubtree=NULL;
	temp->rsubtree=NULL;

	//make pointers from parent to child
	(*node)=temp;

	char choice;
	printf("Do you want a Left Subtree for node with data %d: ",temp->data);
	getchar();
	scanf("%c",&choice);
	if(choice=='y')
	{
		createTree(&temp->lsubtree);
	}

	printf("Do you want a Right Subtree for node with data %d: ",temp->data);
	getchar();
	scanf("%c",&choice);
	if(choice=='y')
	{
		createTree(&temp->rsubtree);
	}

}

void preorder(struct treenode *node)
{
	if(node!=NULL)
	{
		printf("%d ",node->data);
		preorder(node->lsubtree);
		preorder(node->rsubtree);
	}

	else
		return;

}

void inorder(struct treenode *node)
{
	if(node!=NULL)
	{
		inorder(node->lsubtree);
		printf("%d ",node->data);
		inorder(node->rsubtree);

	}
	else return;
}

void postorder(struct treenode *node)
{
	if(node!=NULL)
	{
		postorder(node->lsubtree);
		postorder(node->rsubtree);
		printf("%d ",node->data);
	}
	else return;
}

int main()
{

	createTree(&start);
	printf("Preorder  : ");
	preorder(start);
	printf("\nInorder   : ");
	inorder(start);
	printf("\nPostorder : ");
	postorder(start);
	printf("\n");
	return 0;
}
