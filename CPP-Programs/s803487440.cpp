#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;
const int mxn=100005;

int main()
{
  fastio;
  
  
  int n;
  cin>>n;
  vi a(n);
  int l=0,ans=0,last=0;
  range(i,0,n)
  {
    cin>>a[i];
    if(i==0)
    {
      last=a[i];
      continue;
    }
    if(a[i]>a[i-1])
    {
      ans=max(ans,l);
      l=0;
      last=a[i];
    }
    else l++;
  }
   ans=max(ans,l);
      l=0;
  cout<<ans;

}
