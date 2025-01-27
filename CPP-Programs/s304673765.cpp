#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,k;    cin>>n>>k;
    ll ans = 0;
    if(k%2 == 1){
        ll tmp = n/k;
        ans = tmp*tmp*tmp;
    }else{
        ll a = 0, b = 0;
        for(ll i = 1; i <= n; i++){
            if(i%k == 0)    a++;
            if(i%k == k/2)  b++;
        }
        ans = a*a*a + b*b*b;
    }
    cout << ans << endl;
}
