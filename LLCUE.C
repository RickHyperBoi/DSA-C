#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node* next;
	struct node* prev;
	int data;
}nod;

nod* front=NULL;
nod* rear=NULL;

void enqueue(int n)
{
    if(front==NULL&&rear==NULL)
    {
        nod* nn=(nod*)malloc(sizeof(nod));
        front=nn;
        rear=nn;
        nn->next=NULL;
        nn->prev=NULL;
        nn->data=n;
    }
    else
    {
    nod* nn=(nod*)malloc(sizeof(nod));
    nn->next=NULL;
    nn->prev=rear;
    rear->next=nn;
    rear=rear->next;
    rear->data=n;
    }
}


int dequeue()
{
    int n;
    if(front==NULL&&rear==NULL)
    {
    printf("Queue is empty\n");
    return 0;
    }
    else if(front==rear)
    {
        n=front->data;
        free(front);
        front=NULL;
        rear=NULL;
        return n;
    }
    else
    {
    nod* ptr;
    n=front->data;
    ptr=front;
    front=front->next;
    free(ptr);
    front->prev=NULL;
    return n;
    }
}

void display()
{
    if(front==NULL&&rear==NULL)
    printf("Queue is empty\n");
    else
    {
    nod* ptr;
	int count;
	count=0;
	ptr=front;
	while(ptr!=NULL)
	{
	count++;
	printf("\nThe data at %d position is %d",count,ptr->data);
	printf("\nThe link to next element at %d position is %p",count,ptr->next);
	ptr=ptr->next;
	}
	printf("\n----------End of queue-------------\n");
    }
}

void main()
{
    int choice,n;
    printf("QUEUE OPERATIONS:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do
    {
        printf("Enter your choice:");
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
            printf("Dequeued element:%d\n",n);
            break;
            case 3:
            display();
            break;
            case 4:
            printf("Exiting...");
            default:
            printf("Invalid choice\n");
        }
    }while(choice!=4);
}