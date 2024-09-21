#include<stdio.h>
#include<math.h>
#define max 4

struct queue
{
	int cue[max];
	int front,rear;
}q;
void enqueue(int num)
{
	if(isFull()==0)
	q.cue[++q.rear]=num;
	else
	printf("Queue is full");
}

int dequeue()
{
	int num;
	if(isEmpty()==0)
	{
	num=q.cue[q.front++];
	return num;
	}
	else
	printf("Queue is empty");
}

int isFull()
{
	if(q.rear==max-1)
	return 1;
	else 
    return 0;
}

int isEmpty()
{
	if(q.rear<q.front)
	return 1;
	else
	return 0;
}

void display()
{
	if(isEmpty()==0)
	{
		int i;
		printf("Queue members:\n");
		for(i=q.front;i<=q.rear;i++)
		printf("%d ",q.cue[i]);
	}
	else
	printf("Queue is empty, cannot be displayed");
}

void main()
{
	int choice,n,flag;
	q.front=0;
	q.rear=-1;
	printf("\n\nQUEUE OPERATIONS\n1.Enqueue\n2.Dequeue\n3.Front\n4.isEmpty\n5.isFull\n6.Display\n7.Exit");
	do{
	printf("\nEnter choice of operation:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("Enter number to enqueue:");
		scanf("%d",&n);
		enqueue(n);
		break;
		case 2:
		n=dequeue();
		printf("The dequeued number is:%d",n);
		break;
		case 3:
		printf("The value at front is:%d",q.cue[q.front]);
		break;
		case 4:
		flag=isEmpty();
		if(flag==1)
		printf("Queue is empty");
		else
		printf("Queue is not empty");
		break;
		case 5:
		flag=isFull();
		if(flag==1)
		printf("Queue is full");
		else
		printf("Queue is not full");
		break;
		case 6:
		display();
		break;
		case 7:
		printf("Exiting...");
		break;
		default:
		printf("Invalid choice");
	}
}while(choice!=7);
}
