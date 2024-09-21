#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int cue[MAX];
int front=-1;
int rear=-1;

int isEmpty()
{
	if(front==-1&&rear==-1)
	return 1;
	else
	return 0;
	
}

int isFull()
{
	if((front==0&&rear==MAX-1)||(front-rear)==1)
	return 1;
	else 
	return 0;
}

void enqueue(int num)
{
	if(isFull()==0)
	{
		if(front==-1&&rear==-1)
		{
			front=rear=0;
			cue[rear]=num;
		}
		else if(front!=0&&rear==MAX-1)
		{
			rear=0;
			cue[rear]=num;
		}
		else
		{
			rear++;
			cue[rear]=num;
		}
	}
	else
	printf("Queue Overflow");
}

int dequeue()
{
	int num;
	if(isEmpty()==0)
	{
		if(front==MAX-1)
		{
			num=cue[front];
			front=0;
		}
		else if(front==rear)
		{
			num=cue[front];
			front=-1;
			rear=-1;
		}
		else
		{
			num=cue[front];
			front--;
		}
		return num;
	}
	else
	{
		printf("Queue Underflow");
		return 0;
	}
}

void display()
{
	int i;
	if(front>rear)
	{
		for(i=front;i<=(MAX-1);i++)
		{
			printf("%d ",cue[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d ",cue[i]);
		}
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",cue[i]);
		}
	}
}

void main()
{
	int choice,num;
	printf("\nCIRCULAR QUEUE");
	printf("\n1.Enqueue\n2.Dequeue\n3.isFull\n4.isEmpty\n5.Display\n6.Exit");
	do
	{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the number to enqueue:");
			scanf("%d",&num);
			enqueue(num);
			break;
			case 2:
			num=dequeue();
			printf("\nDequeued number:%d",num);
			break;
			case 3:
			if(isFull()==1)
			printf("Queue is full");
			else
			printf("Queue is not full");
			break;
			case 4:
			if(isEmpty()==1)
			printf("Queue is empty");
			else
			printf("Queue is not empty");
			break;
			case 5:
			display();
			break;
			case 6:
			printf("Exiting...");
			break;
			default:
			printf("Invalid choice");
		}
	}while(choice!=6);
}
