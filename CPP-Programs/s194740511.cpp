#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<tuple>
#include<vector>
#include<cstdlib>
#include<cstdint>
#include<stdio.h>
#include<cmath>
#include<limits>
#include<iomanip> 
#include<ctime>
#include<climits>
#include<random>
#include<queue>
#include<map>


using namespace std;

template <class T> using V = vector<T>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1LL << 60;

using ll = long long;
using db = long double;
using st = string;
using ch = char;
using vll = V<ll>;
using vpll =V<pair<ll,ll>>;
using vst = V<st>;
using vdb = V<db>;
using vch = V<ch>;
using graph = V<V<int>>;
using pq = priority_queue<ll>;



#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define bgn begin()
#define en end()
#define SORT(a) sort((a).bgn,(a).en)
#define REV(a) reverse((a).bgn,(a).en)
#define fi first
#define se second
#define sz size()
#define gcd(a,b) __gcd(a,b)
#define pb(a) push_back(a);
#define ALL(a)  (a).begin(),(a).end()




ll Sum(ll n) {
ll m=0;
  while(n){
    m+=n%10;
    n/=10;
  }
  return m;
}



const int MAX = 510000;
// change
const int MOD = 998244353;
 
long long fac[MAX], finv[MAX], inv[MAX];
 
void Comuse() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}


#define comuse Comuse()

ll combi(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll perm(int n,int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] % MOD) % MOD;
}

ll modpow(ll a,ll n,ll mod){
  ll ans=1;
  while(n>0){
    if(n&1){
      ans=ans*a%mod;
    }

    a=a*a%mod;
    
    n>>=1;
  }

  return ans;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

ll modcombi(int n,int k,int mod){
  ll ans=1;
  for(ll i=n;i>n-k;i--){
    ans*=i;
    ans%=mod;
  }
  for(ll i=1;i<=k;i++){
    ans*=modinv(i,mod);
    ans%=mod;
  }

  return ans;
}

ll lcm(ll a,ll b){
  ll n;
  n=a/gcd(a,b)*b;
  return n;
}


vll div(ll n){
  vll ret;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      ret.push_back(i);
      if(i*i!=n){
        ret.push_back(n/i);
      }
    }
  }
  SORT(ret);
  return (ret);
}

vector<bool> isprime(MAX+100,true);

void primeuse(){
  isprime[0]=false;
  isprime[1]=false;
  for(int i=2;i<MAX+50;i++){
    int up=sqrt(i)+1;
    for(int j=2;j<up;j++){
      if(i%j==0){
        isprime[i]=false;
      }
    }
  }
}




void Solve();


const int MAX_N = 131072;
//segment tree 
int NN;
int seg[MAX_N*2-1];
void seguse(){
  for(int i=0;i<2*NN-1;i++){
    seg[i]=INT_MAX;
  }
}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(20)<<fixed;
  Solve();
}



/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/
//segtreeの葉の先頭の添え字はN-1
void Solve(){
  ll n,k;
    cin>>n>>k;
  ll ans=0;
  vll A(n+1);
  FOR(i,1,n+1){
    cin>>A[i];
  }
  FOR(i,1,n+1){
    A[i]+=A[i-1];
  }

  FOR(i,0,n+1){
    A[i]-=i;
    A[i]%=k;
  }
  
  
  if(n<k){
    ll count=1;
    SORT(A);
    FOR(i,1,n+1){
      if(A[i]==A[i-1]){
        count++;
      }
      else{
        ans+=count*(count-1)/2;
        count=1;
      }
    }
    ans+=count*(count-1)/2;
    cout<<ans<<"\n";
    return;
  }

  map<ll,ll> m;
  FOR(i,0,k-1){
    m[A[i]]++;
  }

  FOR(i,0,n-k+2){
    m[A[i+k-1]]++;
    ans+=m[A[i]]-1;
    m[A[i]]--;
  }
  FOR(i,n-k+2,n+1){
    ans+=m[A[i]]-1;
    m[A[i]]--;
  }
  cout<<ans<<"\n";
}