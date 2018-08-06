#include<stdio.h>
#include<stdlib.h>
struct Dll
{
	struct Dll* prev;
	struct Dll*next;
	int data;
}* start;
void createlist(int n);
void insertafter(int x,int data);
void insertbefore(int x,int data);
void display();

int main()
{
	int data,n,ch,x;
	printf("\nEnter the total number of nodes to be created:");
	scanf("%d",&n);
	createlist(n);
	while(1)
	{
		printf("\n1.Insert after x\n2.Insert before x\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the number after which the node is to be inserted:");
				scanf("%d",&x);
				printf("\nEnter a number to be inserted in the list:");
				scanf("%d",&data);
				insertafter(x,data);
				break;
				
            case 2:
            	printf("\nEnter the number before which the node is to be inserted:");
				scanf("%d",&x);
				printf("\nEnter a number to be inserted in the list:");
				scanf("%d",&data);
				insertbefore(x,data);
				break;
            	
            case 3:
            	printf("\nThe list is:");
            	display();
            	break;
           case 4: 	
            	exit(0);
            	break;
            default:
            	break;
				
				
				
				
		}
	}
	
}
void createlist(int n)
{
 struct Dll *newDll, *temp;
    int data, i;

    start = (struct Dll *)malloc(sizeof(struct Dll));

    if(start == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of Dll 1: ");
        scanf("%d", &data);

        start->data = data; // Link data field with data
        start->next= NULL;
		start->prev=NULL;// Link address field to NULL

        temp = start;

        
        for(i=2; i<=n; i++)
        {
            newDll = (struct Dll *)malloc(sizeof(struct Dll));
            if(newDll == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of Dll %d: ", i);
                scanf("%d", &data);

                newDll->data = data; 
                newDll->next = NULL;
                newDll->prev=temp;
                temp->next = newDll; 
                temp = temp->next; 
            }
        }

        printf("DOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void insertafter(int x,int data)
{
	struct Dll*p,*q=start;
	p=(struct Dll*)malloc(sizeof(struct Dll));
	p->data=data;
	while(q->next!=NULL)
	{
		
		if(q->data==x)
		{
		
		p->next=q->next;
		p->prev=q;
		if(q->next!=NULL)
		{
		
		q->next->prev=p;
		}
		q->next=p;
		break;	
		}
		else
		{
			q=q->next;
		}
			
	}
}
void insertbefore(int x,int data)
{
	struct Dll*p,*temp=start;
	p=(struct Dll*)malloc(sizeof(struct Dll));
	p->data=data;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			p->next=temp;
			p->prev=temp->prev;
			if(temp->prev!=NULL)
			{
				temp->prev->next=p;
			}	
			temp->prev=p;	
			printf("%d",temp->prev->next);
			printf("%d",temp->prev);
			break;
	
		}	
		else
		{
			temp=temp->next;
		}		
	}
	
}
void display()
{
	struct Dll *temp;
    if(start == NULL)
    {
        printf("\nList is empty.");
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            printf("\nData = %d\n", temp->data);
            temp = temp->next;                 
        }
    }
}
