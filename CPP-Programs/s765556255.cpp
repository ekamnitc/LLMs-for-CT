#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll MOD = INF + 7;

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n & 1)ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    ll m = n - 1;
    map<ll, ll> mp;
    for(ll i = 2; i * i <= m; i++){
        while(m % i == 0){
            mp[i]++;
            m /= i;
        }
    }
    if(m != 1)mp[m]++;
    m = n - 1;
    map<ll, ll> seen;
    for(ll i = 1; i * i <= m; i++){
        if(m % i == 0){
            seen[i] = 1;
        }
    }

    ll res = 1;
    for(auto m : mp){
        res *= (1 + m.second);
    }


    for(ll i = 2; i * i <= n; i++){
        if(seen[i] == 1)continue;
        ll cop = n;
        while(cop % i == 0){
            cop /= i;
        }
        if(cop == 1)res++;
        else if((cop - 1) % i == 0)res++;
    }
    cout << res << endl;
}