#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m=1e32,s,p,j,i,a[500];
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=a[0];i<=a[n-1];i++)
    {
        s=0;
        for(j=0;j<n;j++)
        {
            p=(a[j]-i);
            s+=(p*p);
        }
        if(s<m)m=s;
    }
    cout<<m<<endl;
    return 0;
}