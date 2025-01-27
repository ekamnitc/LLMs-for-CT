#include <bits/stdc++.h>

using namespace std ;
typedef long long ll;
typedef string str;
typedef vector<int> vint;
typedef vector<double> vdou ;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef vector<str> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii ;

#define REP(i, n) for (ll (i) = 0; (i) < (ll)(n); i++) 
#define FOR(i, a, b) for(ll (i) = a; (i) < (ll)b; i++)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(x)  (ll)x.size()
#define SP(x)  setprecision((ll)x)

const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数

//-------------------------------------------------
// 
void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}


//-------------------------------------------------
// メモ
/*






*/
//-------------------------------------------------


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, c, k ;
  cin >> n >> c >> k ;
  vll tim(n) ;
  ll ans = 0 ;
  REP(i,n){
    cin >> tim[i] ;
  }
  sort(ALL(tim)) ;
  
  
  bool f = true ;
  ll end ;
  
  int i=0;
  while(i<n){
    if(f){
      end = tim[i]+k ;
      ans++ ;
    }
    int j = 1 ;
    int ii = i ;
    while(j<c && ii+j<n){
      if(end>=tim[ii+j]){
        i++ ;
      }
      else{
        break ;
      }
      j++ ;
    }
    i++ ;
  }
  cout << ans <<endl ;
      
    
      
      
  return 0 ;
}