#include<iostream>
using namespace std;
int main()
{
	int a,n,l=0,u;
	cout<<"\nEnter the number of element in  array:\n";
	cin>>n;
	u=n-1;
	int ar[n];
	cout<<"Enter the elements in ascending order:";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"Enter element to be searched:";
	cin>>a;
	int m;
	while(l<=u)
	{
		m=(l+u)/2;
		if(a<ar[m])
		{
			u=m-1;
		}
		else if(a>ar[m])
		{
			l=m+1;
		}
			else if( ar[m]==a)
				{
					cout<<"\nFound";
					break;
				}	
				else
				{
					cout<<"NOT found";
				}
	}
	
}
