#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;


int main(){
   ll n;cin >>n;
   ll lcm=1;
    for (int i = 0; i < n; ++i) {
        ll t;cin>>t;
        ll g=__gcd(t,lcm);
        lcm=lcm/g*t;
    }
    cout <<lcm<<endl;
}