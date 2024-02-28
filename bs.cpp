#include<iostream>
using namespace std;
struct node
{
	float data;
	node *link;
};

node	*createnode()
{
	node	*ptr;
	ptr=new node;
	ptr->data=0;
	ptr->link=NULL;
	return ptr;
}
int main()
{
	node	*a[10],*nptr,*temp;
	float e[10],x;
	int	i,k,n,loc,h;
	//if(a[i]==NULL)
	 // continue;
	for(i=0;i<10;i++)
	  a[i]=NULL;
	cout<<"Enter n value";
	cin>>n;
	cout<<"\nEnter the Elements";
	for(i=1;i<=n;i++)
	{
	  cin>>x;
	  nptr=createnode();
	  nptr->data=x;
	  loc=x*10;
	  if(a[loc]==NULL)
		a[loc]=nptr;
	  else
	 {
          node	*temp=a[loc];
	  while(temp->link!=NULL)
		temp=temp->link;
	  temp->link=nptr;
	 }
	}
	cout<<"\nBucket contains:\t";
	for(i=0;i<=9;i++)
	{
		if(a[i]==NULL)
		{
			cout<<"\nBucket\t"<<i<<"\t is empty";
			continue;
		}
		else
		{
			cout<<"\nBucket\t"<<i<<" :";
			temp=a[i];
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->link;
			}
		}
	}
	cout<<"\n";
	for(i=0;i<=9;i++)
	{
		if(a[i]==NULL)
		  continue;
		else
		{
			k=0;
			temp=a[i];
			while(temp!=NULL)
			{	
				e[k]=temp->data;
				k++;
				temp=temp->link;
			}
		
		for(h=2;h<k;h++)
		{	
			float v=e[h];
			int z=h-1;
			while(z>0&&e[z]>v)
			{
				e[z+1]=e[z];
				z=z-1;
			}
			e[z+1]=v;
			for(int i=1;i<k;i++)
			{
				cout<<e[h]<<"\t";
	
			}
		}
		}
	}
	return 0;
}
