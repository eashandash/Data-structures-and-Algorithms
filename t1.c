
#include<stdio.h>

int arr[100],count;

void inorder(int pos)
{
int i,j;
i = 2*pos + 1;
if(arr[i] != 0)
inorder(i);

printf("\t %d",arr[pos]);

j = 2*pos +2;
if(arr[j] != 0)
inorder(j);

}
void preorder(int pos)
{
int i,j;
printf("\t %d",arr[pos]);
//i = 2*pos + 1;
i++;
if(arr[i] != 0)
inorder(i);
//j = 2*pos +2;
j++;
if(arr[j] != 0)
inorder(j);

}
void postorder(int pos)
{
int i,j;

//i = 2*pos + 1;
i++;
if(arr[i] != 0)
inorder(i);
//j = 2*pos +2;
j++;
if(arr[j] != 0)
inorder(j);
printf("\t %d",arr[pos]);

}


void main()
{
int i,num,choice;

for(i=0;i<100;i++)
arr[i] = 0;

do
{
printf("enter your choice \n 1.Insert into tree \n 2.delete from tree \n 3. search for an element in tree \n 4. inorder traversal\n5.pre\n6.post\n");
printf("7. exit\n");
scanf("%d",&choice);

switch(choice)
{

case 1:
printf("enter element");
scanf("%d",&num);
arr[count] = num;
count++;
break;

case 2:
printf("\n enter the element to be deleted");
scanf("%d",&num);
for(i=0;i<count;i++)
{
if(arr[i]==num)   {
count--;
arr[i] = arr[count];
arr[count] = 0;
break;
}}
if(i==count)
printf("\n element not found");
break;

case 3:
 printf("\n enter the element to be searched");
scanf("%d",&num);
for(i=0;i<count;i++)
{
if(arr[i]==num)   {
printf("\n element found");
break;
} }
if(i==count)
printf("\n element not found");

break;

case 4:
inorder(0);
break;
case 5:
    preorder(0);
    break;
case 6:
    postorder(0);
    break;
}
}while(choice != 7);

}
