#include<iostream>
using namespace std;
int n,hs;
void mh(int a[],int i)
{
	int l,r,large;
	l=2*i;
	r=2*i+1;
	if(l<=hs && a[l]>a[i])
		large=l;
	else
		large=i;
	if(r<=hs && a[r]>a[large])
		large=r;
	if(large!=i)
	{
		swap(a[i],a[large]);
		mh(a,large);
	}
}
void bmh(int a[])
{
	hs=n;
	for(int i=(n/2);i>=1;i--)
	  mh(a,i);
}
void hsort(int a[])
{
	int c=0;
	bmh(a);
	for(int i=n;i>=2;i--)
	{
	swap(a[1],a[i]);
	c++;
	cout<<"The elements after "<<c<<" iteration\n"; 
	for(int j=1;j<=n;j++)
	  cout<<a[j]<<"\t";
	cout<<"\n";
	hs=hs-1;
	mh(a,1);
	}
}

int main()
{
	int a[15],i,j;
	cout<<"Enter n value: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(i=1;i<=n;i++)
	  cin>>a[i];
	hsort(a);
	cout<<"The elements after sorting"; 
	for(int i=1;i<=n;i++)
	  cout<<a[i]<<"\t";
	return 0;
}
