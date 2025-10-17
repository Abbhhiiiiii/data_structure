#include<stdio.h>
#define MAX_SIZE 10

int a[MAX_SIZE], top = -1;

void push(int item)
{
	if(top >=MAX_SIZE - 1)
 	{
 		printf("Stack is Full\n");
 	}
 	else 
 	{
 		top = top + 1;
 		a[top] = item;
 	}
}

void pop()
{
	if(top<0)
	{
		printf("Stack is Empty\n");
	}
	else 
	{
		printf("Poped Element is :%d\n",a[top]);
		top = top - 1;
	}
}

void display()
{
	if (top >= 0)
	{
		printf("Stack Elements are:\n");
		for (int i = top; i >= 0;i--)
	{
		printf("%d\n",a[i]);
	}
	}
	else 
	{
		printf("Stack is empty\n");
	}
}
	
int main()	
{
 	int count = 0, n, value;
 	
 	while (count != 1)
 	{
 		printf(" 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n Choose a Choice: ");
 		scanf("%d",&n);
 		
 		if(n == 1)
 		{
 			printf("Enter a value");
 			scanf("%d",&value);
 			push(value);
 		}
 		else if(n == 2)
 		{
 			pop(top);
 		}
 		else if(n == 3)
 		{
 			display();
 		}
 		else if(n == 4)
 		{
 			count++;
 			printf("Exited...!\n");	
 		}
 		else
 		{
 			printf("Invalid Number...!\n");
 		}
 		
 	}
 		
	
return(0);
}	
	
	
