#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
ll gcd (ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a * b / gcd(a,b);
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll q = lcm(c,d);
    ll ans = 0;
    ans += b/c + b/d - b/q;
    ans -= (a-1)/c + (a-1)/d - (a-1)/q;
    cout << b - a  + 1 - ans ;

    return 0;
}