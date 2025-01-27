#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define db double
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
using namespace std;
 
 ll mod=1e9 +7;
 
ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
 
vector<bool>  prime(90000002,true);
void Sieve() 
{ 
   
    for (int p=2; p*p<=90000001; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=90000001; i += p) 
                prime[i] = false; 
        } 
    } 
}

const ll M=200006;
ll f[M],inv[M];

void compute(){
    f[0]=1;
    rep(i,1,M-1){
        f[i]=(1LL*i*f[i-1])%mod;
    }
    inv[M-1]=expo(f[M-1],mod-2,mod);
    for(ll i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%mod;
    }
}
ll C(ll n,ll r){
    return (1LL*((1LL*f[n]*inv[r])%mod)*inv[n-r])%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // compute();
    // Sieve();
    ll tests=1;
    // cin>>tests;
    while(tests--)
    {
     ll a,b,k;
     cin>>a>>b>>k;
     if(k>=a)
     {
      k-=a;
      a=0;
      b-=k;
      b=max(b,0LL);
     }
     else
     {
      a-=k;
     }
     cout<<a<<" "<<b;

    }
    return 0;
   }