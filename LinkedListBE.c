#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;          
    struct node *next; 
}*start;


void createList(int n);
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void displayList();


int main()
{
    int n, data;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertNodeAtBeginning(data);
	printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertNodeAtEnd(data);
    printf("\nData in the list \n");
    displayList();

    return 0;
}



void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    start = (struct node *)malloc(sizeof(struct node));

    if(start == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        start->data = data; // Link data field with data
        start->next = NULL; // Link address field to NULL

        temp = start;

        
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL;
                temp->next = newNode; 
                temp = temp->next; 
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}



void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = start; 
        start = newNode;          

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}



void insertNodeAtEnd(int data)
{
	struct node*a=start,*b;
	
	b=(struct node*)malloc(sizeof(struct node));
	if(a==NULL)
	{
	printf("Memory unallocated");
	}
	b->data=data;
	b->next=NULL;
	while(a->next!=NULL)
	{
		a=a->next;
	}
	a->next=b;
}
void displayList()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;                 
        }
    }
}
