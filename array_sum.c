#include<stdio.h>
int main()
{
	int a[5], limit, i, sum=0;
	printf("Enter the number of elements to add array:");
	scanf("%d", &limit);
	
	if (limit>5)
	   {
	    printf("Invalid Input\n");
	   }
	else 
	  {
	printf("Enter The Element of The Array:\n");
	for(i=0;i<limit;i++)
	 {
	    scanf("%d", &a[i]);
	 }
	 for(i=0;i<limit;i++)
	 {
	     sum += a[i];
	 }
	 printf("Sum of Array Elements: %d\n",sum);
          }
}	 
 
