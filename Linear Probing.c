//linear probing

#include <stdio.h>
#include <stdlib.h>


 int hashArraySize = 10;
//int *hashArray = (int *) malloc(sizeof(int)*10);
int hashArray[10] = {0};
int tombstone = -9999999;
int numberOfElementsInHashTable =0;


int hash(int key);
void display();
void insert(int key);
int delete(int key);
int  search(int key);




int main()
{
	system("cls");
	printf("\n\nHASHING - OPEN ADDRESSING -linear probing");


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
{
	int i ;
	for(i=0;i<hashArraySize;i++)
	{
		if(hashArray[i]==tombstone || hashArray[i] == 0)
			printf(" __ ");
		else
			printf(" %d ",hashArray[i]);
	}
}

void insert(int key)
{
	if(numberOfElementsInHashTable == hashArraySize){
		printf("\n The hash table is full ");
		return  ;
	}

	int index = hash(key);
	while(hashArray[index] != 0 && hashArray[index] != tombstone)
	{
		index = (index+1) % hashArraySize;
	}
	hashArray[index] = key;
	display();
	numberOfElementsInHashTable++;
}

int delete(int key)
{
	int index = search(key);
	if(index == -1)
		printf("\n Element not found");
	else
		hashArray[index] = tombstone;
	display();
	
}



int  search(int key)
{
	int index = hash(key);
	int i =0,flag=0;
	while(hashArray[index] != 0 && i<= hashArraySize )
	{
		
		 if(hashArray[index] == key)
			{	flag = 1;
				return index;
			}  
		
		index = (index+1) % hashArraySize;
		i++;
	}
	return -1;

}




