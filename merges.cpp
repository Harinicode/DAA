#include<iostream>
using namespace std;
int n,c=0,count=0;
void merge(int a[],int p,int q,int r1)
{	
	int n1,n2,i,j,k,l[15],r[15];
	n1=q-p+1;
	n2=r1-q;
	for(i=1;i<=n1;i++)
	  l[i]=a[p+i-1];
	for(j=1;j<=n2;j++)
	  r[j]=a[q+j];
	l[n1+1]=100000;
	r[n2+1]=100000;
	i=1;
	j=1;
	for(k=p;k<=r1;k++)
	{
		count++;
		if(l[i]<=r[j])
		{
			a[k]=l[i];
			++i;
		}
		else
		{
			a[k]=r[j];
			j=j+1;
		}

	}
}
void ms(int a[],int p,int r)
{
	int q,j;
	if(p<r)
	{
	q=(int)((p+r)/2);
	ms(a,p,q);
	ms(a,q+1,r);
	merge(a,p,q,r);
	c++;
	cout<<"\nElements after "<<c<<" iteration\n";
	for(j=1;j<=n;j++)
	  cout<<a[j]<<"\t";
	}
}
int main()
{
	int a[30],i,j;
	cout<<"Enter n value: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(i=1;i<=n;i++)
	  cin>>a[i];
	ms(a,1,n);
	cout<<"\nTotal no. of Comparisions: "<<count;
	cout<<"\nElements after sorting: ";
	for(i=1;i<=n;i++)
	  cout<<a[i]<<"\t";
}
