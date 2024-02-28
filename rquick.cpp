#include<iostream>
#include<ctime>							//#include<time.h>
#include <stdlib.h>
using namespace std;
int count=0;
int partition(int a[],int p,int r)
{
	int x,i,j;
	x=a[r];				//pivot
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
	  count++;
	  if(a[j]<=x)
	  {
		i++;
		swap(a[i],a[j]);
	  }
	}
	swap(a[i+1],a[r]);
	return i+1;
}
int randomized_partition(int a[],int p,int r)
{
	srand(time(0));
	int i=p+rand()%((r+1)-p);
	swap(a[r],a[i]);
	return partition(a,p,r);
}
void r_qs(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
	  q=randomized_partition(a,p,r);
	  r_qs(a,p,q-1);
          r_qs(a,q+1,r);
	}
	
}

int main()
{
	/*
		srand(time(0));
		int p=4,r=18;
		int i=p+rand()%((r+1)-p);
		cout<<i;
		
	*/
	int a[25],n,p,q,r;
	cout<<"Enter n value: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	r_qs(a,1,n);
	cout<<"Array after sorting\n";
	for(int i=1;i<=n;i++)
	  cout<<a[i]<<"\t";
	cout<<"\nNo. of comparisions :"<<count;
	return 0;
}
