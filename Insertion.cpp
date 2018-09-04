#include<iostream>
using namespace std;
 int main()
 {
 	  int n,i,j,temp;
 	  cout<<"\nEnter number of elements:\n";
 	  cin>>n; 
 	  int ar[n];
 	  cout<<"\nEnter the elements in an array:\n";
 	  for(int i=0;i<n;i++)
 	  {
 	  	cin>>ar[i];
	   }
 	  for( i=1;i<n;i++)
 	  {
 	  	for( j=0;j<=n;j++)
 	  	{
 	  		if(ar[j]>=ar[i])
 	  		{
 	  			temp=ar[i];
 	  			ar[i]=ar[j];
 	  			ar[j]=temp;
 	  			
			   }
		   }
	   }
	   cout<<"\nArray after sorting: \n";
	    for(int i=0;i<n;i++)
 	  {
 	  cout<<ar[i]<<" ";
	   }
 }
