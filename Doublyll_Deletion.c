#include<stdio.h>
#include<stdlib.h>
	struct Dll
{
	struct Dll* prev;
	struct Dll*next;
	int data;
}* start;
	void createlist(int n);
	void deletenode(int data);
	void delete_beginning();
	void display();

int main()
{
	int data,n,ch,x;
	printf("\nEnter the total number of nodes to be created:");
	scanf("%d",&n);
	createlist(n);
	while(1)
	{
		printf("\n1.Delete x\n2.Delete from beginning\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the number in the node  to be deleted:");
				scanf("%d",&data);
				deletenode(data);
				break;
				
            case 2:
            	delete_beginning();
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
	void deletenode(int data)
	{
		struct Dll*p=start;
		while(p->next!=NULL)
		{
			
			if(p->data==data)
			{
				p->prev->next=p->next;
				p->next->prev=p->prev;
				free(p);
				break;
			}
			else 
			p=p->next;
		}
	}
	void delete_beginning()
	{
		if(start!=NULL)
		{
		start=start->next;
		start->prev=NULL;
		printf("Successfully deleted");
		}
		else
		{
			printf("Not deleted");
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
