#include<iostream>
using namespace std;				
int hs,n;
void maxheapify(int a[],int i)
{
	int l,r,largest;
	l=2*i;								//display each iteration
	r=2*i+1;
	if(l<=hs&&a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<=hs&&a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		maxheapify(a,largest);
	}
}
void bmh(int a[])
{
	hs=n;
	for(int i=(int)n/2;i>=1;i--)
		maxheapify(a,i);
}
void heapsort(int a[])
{
	bmh(a);
	for(int i=n;i>=2;i--)
	{
		swap(a[1],a[i]);
		hs=hs-1;
			maxheapify(a,1);
	}	

	
}
int main()
{
	int a[25];
	cout<<"Enter the no. of elements: ";
	cin>>n;
	cout<<"Enter the elements\n";
	for(int i=1;i<=n;i++)
		cin>>a[i];
	heapsort(a);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<"\t";
	return 0;
}
