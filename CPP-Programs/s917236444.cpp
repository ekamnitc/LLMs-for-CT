#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int maxn =5e5+10;
#define pb push_back

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    vector<int>ans;
    cin>>s;
    reverse(s.begin(),s.end());
    int r=0;
    while(r<=n-1)
    {
        int f=0;
        int step=0;
        for(int i=1;i<=m;i++)
        {
            if(r+step==n)
                break;
            if(s[r+i]=='1')
                continue;
            step=i;
            f=1;
        }
        if(f==0)
        {
            cout<<-1<<'\n';
            return 0;
        }
        ans.pb(step);
        r+=step;
    }
    reverse(ans.begin(),ans.end());
    for(auto &v:ans)
        cout<<v<<" ";









}
