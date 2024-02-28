#include<iostream>
using namespace std;
int x=1;
void cs(int a[],int n,int e)
{
	int  b[10],c[10],i;
	for(i=0;i<=9;i++)
		c[i]=0;
	for(i=1;i<=n;i++)
	  c[(a[i]/e)%10]++;
										//displaying 
	for(i=1;i<=9;i++)
	  c[i]= c[i]+c[i-1];
	for( i=n;i>=1;i--)
	{
		b[c[(a[i]/e)%10]]=a[i];
		c[(a[i]/e)%10]--;
	}
	for(i=1;i<=n;i++)
		a[i]=b[i];
	cout<<"Array at "<<x<<"'s place\n";
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<"\n";
	}
	x=x*10;
}
int main()
{
	int a[10],k=-10000,n,i,e;
	cout<<"Enter n value: ";
	cin>>n;
	cout<<"\nEnter the elements: ";
	for(i=1;i<=n;i++)
	  cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]>k)
		{
			k=a[i];
		}
	}
	for(e=1;(k/e)>0;e*=10)
	{
		cs(a,n,e);
	}
	cout<<"\nArray after sorting\n";
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}
