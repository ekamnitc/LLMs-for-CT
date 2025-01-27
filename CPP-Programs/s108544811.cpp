//FIRST THINK THEN CODE.

#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
//#define MOD 998244353
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rrep(i,a,b) for(ll i=a;i>b;--i)
#define FOR(i,n)  for(ll i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define popcount(x) __builtin_popcountll(x)

const int M=1000000007;
const int MM=998244353;


 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
  if(m<=1)return 0;
  a%=m;
  ll ans=1LL;
  while(b)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }
 
return ans;
}


 
ll poww(ll a,ll b)
{ 
  
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }
 
return ans;

}

template<typename T,typename F>
void chmax( T &a,F b){
  if(b>a)a=b;
}

template<typename T,typename F>
void chmin( T &a,F b){
  if(b<a)a=b;
}

const ll N=1e5+5;




int main()
{ 

IOS;


string s;cin>>s;

vl a(13);

ll n=s.size();

ll ini=0;

for(ll i=0;i<n;i++){
  if(s[i]=='?')continue;
  ll dig=s[i]-'0';
  ll d=powM(10,n-i-1,13)*dig%13;
  ini=(ini+d)%13;
}

a[ini]=1;

//cout<<ini<<endl;

for(ll i=0;i<n;i++){
  if(s[i]=='?'){

   vl temp(13);

   ll ex=powM(10,n-i-1,13);
   for(ll j=0;j<10;j++){
    ll f=ex*j%13;
    for(ll k=0;k<13;k++){
        //f=(f+k)%13;
       // (temp[f]+=a[k])%=M;
      (temp[(f+k)%13]+=a[k])%=M;
    }
  }
  for(ll j=0;j<13;j++)a[j]=temp[j];
}
else continue;

}

cout<<a[5]<<endl;


return 0;
 
}
