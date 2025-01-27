#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int M = 1e9+7;

using namespace std;

main()
{
    fast;
    int n,s[1001]={0},i,j;
    s[0]=s[1]=1;
    vector<int> p;
    for (i=2;i<=1000;i++)
    {
        if (!s[i])
        {
            p.pb(i);
            for (j=i*i;j<=1000;j+=i)
                s[j]=1;
        }
    }
    ll f,cnt,ans=1;
    cin>>n;
    for (i=0;i<p.size() && p[i]<=n;i++)
    {
        f=p[i];
        cnt=0;
        while (f<=n)
        {
            cnt+=n/f;
            f*=p[i];
        }
        ans=(ans*(cnt+1))%M;
    }
    cout<<ans<<endl;
}
