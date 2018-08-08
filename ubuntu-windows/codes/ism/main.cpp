#include <iostream>

using namespace std;

int main()
{
    int adj[][]=;
    int b[10][10];
    int ctr,n=2;
    while(n>0)
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i==j)
                {
                    reach[i][j]=adj[i][j+1;
                }

            }
            if((reach[i][j]%2)==0)
            {
                reach[i][j]=0;
            }
            else
            {
                reach[i][j]=1;
            }
        }

    }
    return 0;
}
