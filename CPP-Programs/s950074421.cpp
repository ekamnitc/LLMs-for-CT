#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;

int main(){

    int N;
    cin >> N;

    vector<ll> a(N);
    ll xor_all = 0;
    rep(i, N){
        cin >> a[i];
        xor_all ^= a[i];
    }
    rep(i, N){
        a[i] &= ~xor_all;
    }

    int pos = 0;
    for(int digit = 59; digit >= 0; digit--){
        ll bit = 1ll << digit;
        bool found = false;
        for(int i = pos; i < N; i++){
            if(a[i] & bit){
                swap(a[pos], a[i]);
                found = true;
                break;
            }
        }
        if(found){
            rep(i, N){
                if(i == pos)continue;
                if(a[i] & bit)a[i] ^= a[pos];
            }
            pos++;
        }
    }

    ll ans = 0;
    for(int i = 0; i < min(N, 60); i++){
        ans ^= a[i];
    }
    cout << ans * 2 + xor_all << endl;
    return 0;

}