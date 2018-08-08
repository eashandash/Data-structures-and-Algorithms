//CHAINING


#include <stdio.h>
#include <stdlib.h>


 int hashArraySize = 10;
//int *hashArray = (int *) malloc(sizeof(int)*10);

int tombstone = -9999999;
int numberOfElementsInHashTable =0;

struct node {
	int key;
	struct node* next;
};

struct node* hashArray[10];
struct node* temp = NULL;

void delete(int key);
int hash(int key);
void display();
void insert(int key);


int main()
{
	system("cls");
	printf("\n\n_HASHING - CHAINING");


	char ch ='i' ;
	int data;

	printf("\n<-- Menu -->\n _________ \n i to insert \n d to display \n r to remove \n q to quit\n\n");


	while(ch != 'q'){
		printf("\nCommand : "); scanf(" %c",&ch);
		
		switch(ch)
		{
			case 'i' :
				printf("\nEnter the element to be inserted  :"); 
				scanf(" %d",&data);
				insert(data);
				break;

			case 'd' :
			display();
				break;

		
			case 'r':
				printf("\n what do you want to delete: ");
				scanf(" %d",&data);
				 delete(data);
				 display();
				
				break;	

			default :
				printf("\n invalid entry\n");

		}

}

	return 0;
}











int hash(int key)
{
	return key % hashArraySize;
}


void display()
{  int i;
	for( i = 0; i<hashArraySize;i++)
	{
		temp = hashArray[i];

		while(temp)
		{
			printf(" --> %d ",temp->key);
			temp = temp->next;
		}
		printf("\n");
	}
}

void insert(int key)
{
	struct node* newNode = malloc(sizeof(struct node *));
	newNode->key = key;
	newNode->next = NULL;

	int index = hash(key);

	if(hashArray[index] == NULL)
		hashArray[index] = newNode;
	else
	{	newNode->next=hashArray[index];
	    hashArray[index]=newNode;
	}
}

void delete(int key)
{
	int index = hash(key);
	struct node* temp = hashArray[index];
	struct node* prev = NULL;


	if(hashArray[index] && (hashArray[index]->key == key))
	{
		hashArray[index] = hashArray[index]->next;
		free(temp);
		temp = NULL;
	}
	else
	{
		prev = temp;
		temp = temp->next;
		while(temp)
		{
			if(temp->key == key)
			{
				prev->next = temp->next;
				free(temp);
				printf("\n Element successfully deleted !");
				return;
			}
			prev = temp;
			temp = temp->next;
		}


		printf("\n Element not found !");

	}
	
}



// int  search(int key)
// {
	

// }




