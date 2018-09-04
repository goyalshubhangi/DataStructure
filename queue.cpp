#include<stdio.h>
#include<conio.h>
typedef struct
{
	int front,rear;
	int items[50];
}queue;
int Is_Empty(queue *);
int Is_Full(queue *);
void Insert(queue *, int);
int Delete(queue *);
void Display(queue *);
int main()
{
	queue q;
	int x;
	q.front=0;
	q.rear=-1;
	char ch='1';
	

	while(ch!='4')
	{
		printf("\n1 INSERT\n2 DELETE\n3 DISPLAY\n4 EXIT");
		printf("\nEnter your choice: ");
		fflush(stdin);
		ch=getchar();
		switch(ch)
		{
			case '1':
				printf("\nEnter The element to be searched:");
				scanf("%d",&x);
				Insert(&q,x);
				break;
				case '2':
					x=Delete(&q);
			printf("\nDeleted element is %d\n",x);
			break;
			case '3':
				Display(&q);
				break;
				case '4':
					break;
					default:
						printf("\n Wrong Choice!!");
						
				}
		
	}
}
int Is_Empty(queue *q)
{
	if(q->rear<q->front)
	return 1;
	else 
	return 0;
}
int Is_Full(queue *q)
{
	if(q->rear==49)
	return 1;
	else 
	return 0;
}
void Insert(queue *q,int x)
{
	if(Is_Full(q))
	{
		printf("\nFULL");
		return;
	}
	q->rear++;
	q->items[q->rear]=x;
}
int Delete(queue *q)
{int x;
if(Is_Empty(q))
{
	printf("Empty");
	}	
	x=q->items[q->front];
	q->front++;
	return x;
	}
void Display(queue *q)
{
	int i;
	if(Is_Empty(q))

{
	printf("\nEmpty");
	return;
}
printf("\n Elements in the queue are\n");
for(i=q->front;i<=q->rear;i++)
printf("%d\n",q->items[i]);
}


