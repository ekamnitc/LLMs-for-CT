#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a>b;
}
const int maxn = 1e5 + 5;
int n;
int l[maxn];
int r[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        l[i] = x;
        r[i] = y;
    }
    sort(l,l+n+1,cmp);
  //  for(int i=0;i<n;i++)
  //      cout<<l[i]<<endl;
    sort(r,r+n+1);
    long long ans = 0;
    for(int i=0;i<=n;i++){
        ans += max(0,l[i] - r[i]);
    }
    cout<<ans * 2<<endl;

    return 0;
}
