#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

ll gcd(ll a, ll b){
    if(a%b==0) return b;
    return gcd(b, a%b);
}

int main(){
    ll n, k;   cin >> n >> k;
    vector<ll> a(n);
    for(int i=0; i<n; i++)  cin >> a.at(i);
    sort(a.begin(), a.end());

    ll x = a[0];
    for(int i=1; i<n; i++)  x = gcd(a[i], x);

    string ans="IMPOSSIBLE";
    if(k<=a.back() && k%x==0) ans = "POSSIBLE";

    cout << ans << endl;   
    
}