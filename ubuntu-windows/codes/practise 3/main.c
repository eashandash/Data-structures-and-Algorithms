//linear search optimization


#include<stdio.h>

void lo(int a[],int n,int x)
{
    int i;
    a[n]=x;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
            break;
    }
    if(i<n)
    printf("\nelement found");
    else
    printf("/n  element not found");


}
 void main()
 {
     int n,i,x;
     printf("\nenter the size of the array");
     scanf("%d",&n);
     int a[n];
     printf("\nenter the  array");
     for(i=0;i<n;i++)
     {
         scanf("%d",&a[i]);
     }
  printf("\nenter the  element");
   scanf("%d",&x);
   lo(a,n,x);
   return (0);
 }
