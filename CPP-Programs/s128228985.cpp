#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;
/*素数判定*/int isPrime(int n){if(n<2){return 0;}for(int i=2; i*i<=n; i++){if(n%i==0){return 0;}}return 1;}

signed _main(){
  int S; cin >> S;
  int X1=0,Y1=0;
  int X2=1000000000;
  int Y2=1;
  int Y3=(S+1000000000-1)/1000000000;
  int X3=1000000000*Y3-S;
  cout << X1 << " "<< Y1 << " "<< X2 << " "<< Y2 << " "<< X3 << " "<< Y3 << endl;
  return 0;
}
