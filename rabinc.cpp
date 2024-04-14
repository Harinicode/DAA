#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char txt[20],pat[20],t[20],p[20];
    int t0,p0,n,m,i,j,s;
    int d=10;
    int q=11;
    t0=0,p0=0;
    cout<<"Enter two strings: ";                        //text and pattern
    cin>>txt>>pat;
    n=strlen(txt);
    m=strlen(pat);
    for(i=0;i<n;i++)
        t[i+1]=txt[i];
    for(i=0;i<m;i++)
        p[i+1]=pat[i];
   int  h=10;
    for(i=1;i<=m;i++)
    {
        p0=(d*p0+p[i])%q;
        t0=(d*t0+t[i])%q;
    }
    for(s=0;s<=n-m;s++)
    {
        if(p0==t0)
        {
            i=s+1;
            for(j=1;j<=m;j++,i++)
            {
                if(t[i]!=p[j])
                {
                    break;
                }
            }
                if(j==m+1)
                    cout<<"Pattern occurs at shift "<<s<<"\n";
        }
            if(s<n-m)
            {

               t0=(d*(t0-t[s+1]*h)+t[s+m+1])%q;
               if(t0<0)
                  t0+=q;
                                                                     //t[s-1]
            }
    }
    return 0;
 }