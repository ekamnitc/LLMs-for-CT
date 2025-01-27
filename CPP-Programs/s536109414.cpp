#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    int s=0;
    rep(i,n) {
        cin >> a[i];
        s+=a[i];
    }
    int cnt=0;
    rep(i,n) {
        if (a[i]*4*m>=s) ++cnt;
    }
    if (cnt>=m) cout << "Yes" << endl;
    else cout << "No" << endl;
     
    return 0;   
}