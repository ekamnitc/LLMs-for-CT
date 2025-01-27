#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,v[60],c[60],r,ans=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>c[i];
    }
    for(int i=0; i< n; i++)
    {
        r=v[i]-c[i];
        if(r>0)
        ans=ans+r;
    }
    cout<<ans<<endl;
    return 0;
}
