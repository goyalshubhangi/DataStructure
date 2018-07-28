#include<iostream>
using namespace std;
int main()
{
	int size=50,ch,exit=1;
	int stack[size],item,top=-1,y;
	do{
		cout<<"\n1.Push\n2.Pop\n3.Display";
		cout<<"\n Enter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
				
				
				if(top==size-1)
				{
				cout<<"STACK OVERFLOW";
				}
				else
				{
				cout<<"\nEnter the element to be inserted: ";
				cin>>item;	
				top++;
				stack[top]=item;;
				}
				break;
							
				
				case 2:
				int y;
				if(top==-1)	
				{
					cout<<"\n STACK UNDERFLOW";
				}
				else
				{
				y=stack[top];
				top--;
				cout<<y;	
				}
				break;
				case 3:
                for (int i = (top - 1); i >= 0; i--)
                cout<<"\n"<<stack[i];
                break;
                default:
	               	exit = 0;
               		break;
	                	
                
			}	
			}while(exit);
	}


