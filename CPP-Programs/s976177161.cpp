#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const int N=2e5+5;
using namespace std;
int a[N],b[N];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    sort(a+1,a+1+n);sort(b+1,b+1+n);
    int l,r;
    if(n%2==0)
    {
        l=a[n/2]+a[n/2+1];r=b[n/2]+b[n/2+1];
    }
    else
    {
        l=a[(n+1)/2];r=b[(n+1)/2];
    }
    cout<<r-l+1<<endl;
    return 0;
}
