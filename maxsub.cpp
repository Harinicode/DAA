#include<iostream>
using namespace std;
int fmcs(int a[],int low,int mid,int high)
{
	int ls=-100000,maxl,maxr;
	int sum=0;
	for(int i=mid;i>=low;i--)
	{
		sum+=a[i];
		if(sum>ls)
		{
			ls=sum;
			maxl=i;
		}
	}
	int rs=-100000;
	sum=0;
	for(int j=mid+1;j<=high;j++)
	{
		sum+=a[j];
		if(sum>rs)
		{
			rs=sum;
			maxr=j;
		}
	}
	return (ls+rs);
}
int fms(int a[],int low,int high)
{
	int ls,rs,cs,mid;
	if(high==low)
		return(low,high,a[low]);
	else
	    mid=int(low+high)/2;
    ls=fms(a,low,mid);
	rs=fms(a,mid+1,high);
    cs=fmcs(a,low,mid,high);
	if(ls>=rs&&ls>=cs)
		return ls;
	else
    if(rs>=ls&&rs>=cs)
		return rs;
	else
		return cs;
		
}
int main()
{
	int a[20],n;
	cout<<"Enter n value: ";
	cin>>n;
	cout<<"Enter the Elements: ";
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	int result=fms(a,1,n);
	cout<<"Maximum Sub Array Value= "<<result<<"\n";
	return 0;
}
