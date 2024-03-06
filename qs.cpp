#include<iostream>
using namespace std;
int count=0,i,c=0,n;
int partition(int a[],int p,int r)
{
	int x,i,j;
	x=a[r];				//pivot
	i=p-1;
	for(j=p;j<r;j++)
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
void qs(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		c++;
		cout<<"The elements after "<<c<<" partition\n"; 
		for(int i=1;i<=n;i++)
		  cout<<a[i]<<"\t";
		cout<<"\n";
		qs(a,p,q-1);
		qs(a,q+1,r);
	}
}

int main()
{
	int a[25],p,q,r;
	cout<<"Enter n value: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	qs(a,1,n);
	cout<<"Array after sorting\n";
	for(int i=1;i<=n;i++)
	  cout<<a[i]<<"\t";
	cout<<"\nNo. of comparisions :"<<count;
	return 0;
}

