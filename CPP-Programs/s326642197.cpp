#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forN(i, n) for(int i = 0; i <n ; ++i)
#define endl "\n"
#define noob (main)
typedef long long ll;
using namespace  std;
typedef vector<int> vi;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int N = 2e5 +5 ;
vi primes(1,2);
void sieve(){
    vi m(N+1,0);
    for(int i = 4; i<N; i+=2)m[i]=1;
    for(int i = 3; i*i<=N; i+=2)if(!m[i])for(int j = i*i; j<N; j+=i)m[j]=1;
    for(int i = 3; i<N; i+=2)if(!m[i])primes.pb(i);
}
bool isPrime(ll x){
    if(x==1)return 0;
    for(auto i:primes){
        if(i*i>x)return 1;
        if(x%i==0)return 0;
    }
    return 1;
}

int n,B[105];
int noob(){
    fastIO;
    cin>>n;
    for(int i = 0 ; i<n-1 ; i++){
        cin>>B[i];
    }
    int ans = B[0] + B[n-2] ;
    for(int i = 1  ; i<n-1 ;i++){
        ans+=min(B[i],B[i-1]);
    }
    cout<<ans;
}

//3
//3 3
//
//0 153 10 10 23
//0 10 10 10 23
