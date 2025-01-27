#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MAX 510000
#define rrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define dcout cout<<fixed<<setprecision(15);

using namespace std;
typedef long long int  ll;
typedef pair<ll, ll> P;

constexpr int MOD = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double pi=3.141592653589793;

template< typename S, typename T >
inline void chmax(S &a, const T &b) { if(a < b) a = b; }
 
template< typename S, typename T >
inline void chmin(S &a, const T &b) { if(a > b) a = b; }
 

//lcm//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//a^n mod p//
ll modpow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modpow(a, n - 1, p)) % p;
  ll t = modpow(a, n / 2, p);
  return (t * t) % p;
}

//inversemod//
ll modinv(ll a, ll m) {
	if(m==0)return (ll)1;
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

//Cmonp//
ll fac[MAX], finv[MAX], inv[MAX];
// 
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 
ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//LARGE n
ll com(ll n,ll m){
    if(n<m || n<=0 ||m<0){
		return 0;
	}
	if( m==0 || n==m){
		return 1;
	}
	ll k=1;
	for(ll i=1;i<=m;i++){
       k*=(n-i+1); 
	   k%=MOD;
	   k*=modinv(i,MOD);
	   k%=MOD;
	}
	return k;
}

//radP
ll rad(ll u, ll p){
ll cnt=0;
	while(u%p==0){
		u/=p;
		cnt++;
	}
	return cnt;
}


////////////////////////////////////////////////////////////////////

int main() {
ll n;
cin>>n;
string ss;
cin>>ss;
string s="";

rrep(i,n){
	s+=ss[i];
}
for(int i=n;i<=2*n-1;i++){
	s+=ss[3*n-1-i];
}
ll ans=0;

for(ll bit=0;bit<(1<<n);bit++){
int nowr=2*n-1;
string sr="";
string sb="";
for(int j=0;j<=n-1;j++){
if(bit & (ll)1<<j) sr+=s[j];
else sb+=s[j];
}
ll dp[n+1][n+1];
rrep(i,n+1){
	rrep(j,n+1){
dp[i][j]=0;
if(i==0 && j==0){dp[i][j]=1; continue;}
if(i>sr.size()||j>sb.size())continue;
if(i){
if(sr[i-1]==s[n-1+i+j])dp[i][j]+=dp[i-1][j];}
if(j){
if(sb[j-1]==s[n-1+i+j])dp[i][j]+=dp[i][j-1];}
if(i+j==n)ans+=dp[i][j];
}
	}
}

cout<<ans<<endl;
return 0;
}


