#include<stdio.h>

int graph[10][10],stack[10],reach[10],n,top=-1;

int instack(int a)
{
	int i;
	for(i=top;i>=0;i--)
		if(a==stack[i])
			return 1;
	return 0;
}

void cyc(int v)
{
  int j,u;
  
	
	reach[v-1]=1;
	
	stack[++top]=v;
	while(top>=0)
	{
		u=stack[top--];
		
		for(j=0;j<n;j++)
		{
			
			
			if(graph[u-1][j]==1 && reach[j]==0)
			{
				
				stack[++top]=u;
				stack[++top]=j+1;
				reach[j]=1;
				break;
				

			}
			
			
			else if(graph[u-1][j]==1 && reach[j]==1 && instack(j+1))
				{			
					printf("\nCyclic!!\n");
					return;
				}
		}
			
	}
	
	printf("\n Acyclic!!\n");
	
}

void main()
{
	//system("clear");
	int num,i,j;
	for(i=0;i<10;i++)
		reach[i]=0;
		
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			graph[i][j]=0;
		
	printf("\n Vertices are 1,2,3...,n");
	printf("\n Enter the number of vertices (n): ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("\nEnter adjecent elements of %d (enter -1 to stop) : ",i);
		num=2;
		while(num!=-1)
		{
			scanf("%d",&num);
			if(num<=n && num>0)
				{
				 graph[i-1][num-1]=1;				 
				}
				
				
				
			else if(num!=-1)
				printf("Entered vertix does not exist!!");
		}
	
	}
	
cyc(1);
}
