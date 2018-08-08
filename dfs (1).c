//DFS TRAVERSAL

#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]
 
void main()
{
    int i,j;  
    int c=0;     //TO FIND WHEATHER IT'S CYCLIC OR ACYCLIC,
                     //N-1 IS THE EDGES FOR ACYCLIC GRAPH
    printf("Enter number of vertices:");
   
    scanf("%d",&n);
 
    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:");
   
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
          {
            scanf(" %d",&G[i][j]);
            
          }
     printf("\n");
    }      
          
        for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       {
        if(G[i][j]==1)
        c++;
       }
       if(c/2==n-1)
       printf("acyclic");
       else
       printf("cyclic ");
               
            
 
    //visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;
 
    DFS(0);
}
 
void DFS(int i)
{
    int j;
    printf("\n%d",i+1);
    visited[i]=1;
    
    for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}


