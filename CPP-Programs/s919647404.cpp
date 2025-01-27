#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi cnt(9);
  rep(i,n){
    int a; cin >> a;
    cnt[min(a/400,8)]++;
  }
  int mn = 0;
  rep(i,8) if(cnt[i]) mn++;
  cout << max(1,mn) << " ";
  cout << mn+cnt[8];
  cout << endl;
  return 0;
}
