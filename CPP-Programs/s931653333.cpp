#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    ll n, x;
    cin >> n >> x;
    if(x == 1 || x == 2*n-1){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";

    vector<ll> ans;
    if(x < n){
        rep(i, n-x)cout << 2*n-1-i << endl;
        rep(i, 2*n-1-(n-x))cout << i+1 << endl;
    }
    else if(x > n){
        for(ll i = x-n+1; i<=2*n-1; ++i)cout << i << endl;
        rep(i, x-n)cout << i+1 << endl;
    }
    else rep(i, 2*n-1)cout << i+1 << endl;
}