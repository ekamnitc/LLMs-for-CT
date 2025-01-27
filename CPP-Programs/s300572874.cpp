#include <bits/stdc++.h>  // This will work only for g++ compiler.

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())
#define mod 1000000007
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

void fast()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
void solve()
{
    ll n,m,c;
    cin >> n >> m >> c;
    ll b[m];
    for(int i=0;i<m;i++) cin >> b[i];
    ll a[m];
    ll co = 0;
    for(int i=1;i<=n;i++)
    {
        ll res = 0;
        for(int i=0;i<m;i++) {cin >> a[i];res+=b[i]*a[i];}
        if(res+c>0) co++;
    }
    cout << co << endl;
}
int main()
{
  fast();
  solve();

return 0;
}
