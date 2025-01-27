#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005];
int main()
{
    long long int i,j,k,z,t,x,y,n;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    z=0;
    for(i=1;i<n;i++)
    {
        if(a[i]+a[i+1]>=k)
        {
            z=i;
            break;
        }
    }
    if(z==0)
        cout<<"Impossible"<<endl;
    else
    {
        cout<<"Possible"<<endl;
        for(i=1;i<z;i++)
        {
            cout<<i<<endl;
        }
        for(i=n-1;i>=z;i--)
            cout<<i<<endl;
    }
}