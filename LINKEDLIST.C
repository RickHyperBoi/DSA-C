#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node* next;
	int data;
}nod;

nod* createll(nod* head)
{
	nod* ptr;
	int write,numnode;
	printf("No. of nodes to create:");
	scanf("%d",&numnode);
	while(numnode>0)
	{
		printf("Enter data:");
		scanf("%d",&write);
		nod* nn=(nod*)malloc(sizeof(nod));
		nn->data=write;
		if(head==NULL)
		{
			nn->next=NULL;
			head=nn;
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next=nn;
			nn->next=NULL;
		}
		numnode--;
	}
	return head;
}

nod* insert_end(nod* head)
{
nod* ptr;
ptr=head;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr=createll(ptr);
return head;
}

nod* insert_beg(nod* head)
{
    nod* ptr;
    ptr=head;
    int write,numnode;
    printf("No. of nodes to create:");
    scanf("%d",&numnode);
    while(numnode>0){
    printf("Enter data:");
	scanf("%d",&write);
	nod* nn=(nod*)malloc(sizeof(nod));
	ptr=head;
	nn->data=write;
	nn->next=ptr;
	head=nn;
	numnode--;
	}
	return head;
}

nod* delete_beg(nod* head)
{
    nod* ptr;
    if(head==NULL)
	printf("\nList empty");
    else
    {
    ptr=head->next;
    free(head);
    head=ptr;
    }
    return head;
}

nod* delete_end(nod* head)
{
    nod* ptr;
    nod* ptr2;
    ptr=head;
    if(head==NULL)
    printf("\nList is empty");
    else
    {
    while(ptr->next!=NULL)
    {
    ptr2=ptr;
    ptr=ptr->next;
    }
    free(ptr);
    ptr2->next=NULL;
    }
    return head;
}

void traversal(nod* head)
{
	nod* ptr;
	int count;
	count=0;
	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		printf("\nThe data at %d position is %d",count,ptr->data);
		printf("\nThe link to next element at %d position is %p",count,ptr->next);
		ptr=ptr->next;
	}
	printf("\n----------End of list-------------\n");

}

nod* delete_k(nod* head)
{
nod* ptr;
nod* ptr2;
int k;
ptr=head;
printf("\nWhich position would you like to delete the node?:");
scanf("%d",&k);
k--;
while(k>0)
{
ptr2=ptr;
ptr=ptr->next;
if(ptr->next==NULL){
printf("\nInvalid position");
return head;
}
k--;
}
ptr2->next=ptr->next;
free(ptr);
return head;
}

nod* insert_k(nod* head)
{
    nod* ptr;
    nod* ptr2;
    int write,numnode,k;
printf("\nWhich position would you like to insert node?:");
scanf("%d",&k);
k--;
while(k>0)
{
ptr=ptr->next;
if(ptr->next=NULL){
printf("\nInvalid position");
return head;
}
k--;
}
printf("No. of nodes to create:");
scanf("%d",&numnode);
	while(numnode>0)
	{
		printf("Enter data:");
		scanf("%d",&write);
		nod* nn=(nod*)malloc(sizeof(nod));
		nn->data=write;
		ptr2=ptr->next;
		ptr->next=nn;
		nn->next=ptr2;
		numnode--;
	}
	return head;
}

nod* insert_af_k(nod* head)
{
nod* ptr;
nod* ptr2;
ptr=head;
int k,write,numnode;
printf("\nEnter the position after which you want to insert node:");
scanf("%d",&k);
k--;
while(k>0)
{
ptr=ptr->next;
k--;
}
ptr2=ptr->next;
printf("No. of nodes to create:");
scanf("%d",&numnode);
while(numnode>0)
{
printf("Enter data:");
scanf("%d",&write);
nod* nn=(nod*)malloc(sizeof(nod));
nn->data=write;
nn->next=ptr2;
ptr->next=nn;
ptr=ptr->next;
numnode--;
}
return head;
}

nod* delete_af_k(nod* head)
{
nod* ptr;
nod* ptr2;
ptr=head;
int k;
printf("\nEnter the position after which you want to insert node:");
scanf("%d",&k);
k--;
while(k>0)
{
ptr=ptr->next;
k--;
}
ptr2=ptr->next;
ptr->next=ptr2->next;
free(ptr2);
return head;
}

void main()
{
    int choice;
	nod* head=NULL;
	head=createll(head);
	printf("LINKED LIST");
	printf("\n1.Insert at Beginning\n2.Insert at end\n3.Delete at beginning\n4.Delete at end\n5.Insert at k\n6.Delete at k\n7.Insert after k\n8.Delete after k\n9.Display\n10.Exit");
	do{
	    printf("\nEnter your choice:");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	        case 1:
	        head=insert_beg(head);
	        break;
	        case 2:
	        head=insert_end(head);
	        break;
	        case 3:
	        head=delete_beg(head);
	        break;
	        case 4:
	        head=delete_end(head);
	        break;
	        case 5:
	        head=insert_k(head);
	        break;
	        case 6:
	        head=delete_k(head);
	        break;
	        case 7:
	        head=insert_af_k(head);
	        break;
	        case 8:
	        head=delete_af_k(head);
	        break;
	        case 9:
	        traversal(head);
	        break;
	        case 10:
	        printf("Exiting...");
	        break;
	        default:
	        printf("Invalid choice");
	    }
	}while(choice!=10);
}
