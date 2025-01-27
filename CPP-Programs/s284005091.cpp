#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  rep(i,m+1)rep(j,n+1){
    if(i*n+j*m-i*j*2 == k){
      cout << "Yes" << ln; return 0;
    }
  }
  cout << "No" << ln;
  return 0;
}