#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node* next;
	int data;
}nod;

nod* head=NULL;
nod* top=NULL;

void push(int n)
{
nod* nn=(nod*)malloc(sizeof(nod));
nn->next=NULL;
top->data=n;
top->next=nn;
top=top->next;
}


int pop()
{
    int n;
    nod* ptr;
    if(top==NULL)
    {
    printf("Stack is empty\n");
    return 0;
    }
    else if(head==top)
    {
        n=top->data;
        free(top);
        top=NULL;
        head=NULL;
        return n;
    }
    else
    {
    ptr=head;
    while(ptr->next!=top)
    ptr=ptr->next;
    free(top);
    top=ptr;
    n=top->data;
    top->next=NULL;
    return n;
    }
}

void display()
{
    if(head==NULL)
    printf("Stack is empty");
    else
    {
    nod* ptr;
	int count;
	count=0;
	ptr=head;
	while(ptr->next!=NULL)
	{
	count++;
	printf("\nThe data at %d position is %d",count,ptr->data);
	printf("\nThe link to next element at %d position is %p",count,ptr->next);
	ptr=ptr->next;
	}
	printf("\n----------Top of Stack-------------\n");
    }
}

void main()
{
    int choice,n;
    nod* nn=(nod*)malloc(sizeof(nod));
    head=nn;
    top=nn;
    head->next=NULL;
    printf("STACK OPERATIONS:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter number to push:");
            scanf("%d",&n);
            push(n);
            break;
            case 2:
            n=pop();
            printf("Popped element:%d\n",n);
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