#include<stdio.h>
int maxsize=5;
struct stack
{
int stacc[100];
int top;
}s;
void main()
{
	int choice;
	s.top=-1;
	do{
	printf("\nStack operations");
	printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5.Exit\n-------------\nEnter choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		push();
		break;
		case 2:
		pop();
		break;
		case 3:
		peek();
		break;
		case 4:
		display();
		break;
		case 5:
		printf("Exiting...");
		break;
		default:
		printf("Invalid choice");
	}
}while(choice!=5);
}
int isFull()
{
if(s.top==(maxsize-1))
return 1;
else
return 0;
}
int isEmpty()
{
	if(s.top==-1)
	return 1;
	else
	return 0;
}
void push()
{
	int check,n;
	check=isFull();
	if(check==1)
	{
		printf("Stack is full");
	}
	else
	{
		s.top=s.top+1;
		printf("Enter number to be pushed= ");
		scanf("%d",&n);
		s.stacc[s.top]=n;
	}	
}
void pop()
{
	int check,n;
	check=isEmpty();
	if(check==1)
	{
		printf("Stack is empty");
	}
	else
	{
		n=s.stacc[s.top];
		printf("Popped number= %d",n);
		s.top=s.top-1;
	}
}
void peek()
{
	int check,n;
	check=isEmpty();
	if(check==1)
	printf("Stack is empty");
	else
	{
	n=s.stacc[s.top];
	printf("Number at top= %d",n);
	}
}
void display()
{
	int check,i;
	check=isEmpty();
	if(check==1)
	printf("Stack is empty");
	else
	{
		for(i=s.top;i>=0;i--)
		{
			printf("%d\n",s.stacc[i]);
		}
	}
}
