#include<iostream>
using namespace std;
int main()
{
	int a[30],b[30],c[30],i,k=-10000,j,n;
	cout<<"Enter n value: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(i=1;i<=n;i++)
	  cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]>k)
		  k=a[i];
	}
	for(i=0;i<=k;i++)
	  c[i]=0;
	for(j=1;j<=n;j++)
	  c[a[j]]= c[a[j]]+1;
										//displaying c
	cout<<"\nContents of 'C' Array:\n";
	for(i=0;i<=k;i++)
	  cout<<c[i]<<"\t";

	for(i=1;i<=k;i++)
	  c[i]= c[i]+c[i-1];

	cout<<"\nContents of 'C' Array as per occurances:\n";
	for(i=0;i<=k;i++)
	  cout<<c[i]<<"\t";

	for( j=n;j>=1;j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]=c[a[j]]-1;
	}

	cout<<"\nArray after sorting\n";
	for(i=1;i<=n;i++)
	  cout<<b[i]<<"\t";
	return 0;
}
