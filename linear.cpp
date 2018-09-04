#include<iostream>
using namespace std;
int main()
{
	int n,x,flag;
	cout<<"\nEnter number of elements in an array: ";
	cin>>n;
	int ar[n];
	cout<<"\nEnter elements in an array:\n";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"\nEnter element  to be searched: ";
	cin>>x;
	for(int i=0;i<=n;i++)
	{
		if(ar[i]==x)
		{
			flag=1;
			break;
		}
		else
		{
		continue;
		}
	}
	if(flag==1)
	{
		cout<<"\nFound";
	}
	else
	{
	cout<<"\nNot Found";
	}
	}
	
