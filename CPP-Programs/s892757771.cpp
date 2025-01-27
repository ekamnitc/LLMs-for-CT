#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(Array) sort(Array.begin(), Array.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define out(ans) cout << ans << endl;
const int MOD = 1000000007;
const int INF = 2147483647;
const ld PI = 3.14159265358979323846;

//------------↓------------- M -------------- E ---------------- M --------------- O ---------------↓--------------//
// コンパイル 
// g++ -std=c++1z
//
// -------型変換--------
// int を string に変換
// string s = to_string(n);
// string を int に変換
// int n = stoi(s);
//
// -------二分探索---------
// k以上の値が最初に現れる時のイテレータ
// lower_bound(data.begin(), data.end(), k)
// kより大きい値が最初の現れる時のイテレータ O(logN)
// upper_bound(data.begin(), data.end(), k)
// kがdataに存在するかをtrue or falseで返す O(logN)
// binary_search(data.begin(), data.end(), k)
// 
//
//
//
//
//
// 
//------------↑------------- M -------------- E ---------------- M --------------- O ---------------↑--------------//


ll modadd(long long a, long long b){return (a%MOD+b%MOD+MOD)%MOD;}
ll modmul(long long a, long long b){return a%MOD*b%MOD%MOD;}
ll modexp(long long a, long long n){if (a==0) return 0; if(n==0)return 1; if(n%2==0){ll e=modexp(a,n/2); return modmul(e,e);} return modexp(a,n-1)*a%MOD;}
ll modinv(long long n){return modexp(n%MOD,MOD-2);}
ll modfact(long long n){long long res=1; for (int i=1; i <= n; ++i){res *= i; res %= MOD;} return res;}
ll modncr(long long n, long long r){long long numer=1;long long denom=1;for(int i=1;i<=r;++i){numer=modmul(numer,n-r+i);denom=modmul(denom,i);}return modmul(numer, modinv(denom));}



int main() {

    int S; cin >> S;
    int N = S/3;
    ll ans = 0;
    for (int n = 1; n <= N; ++n) {
        ll a, b, c;
        a = modfact(S-2*n-1);
        b = modfact(S-3*n);
        c = modfact(n-1);
        ll tmp = modmul(a, modinv(modmul(b,c)));
        ans += tmp;
        ans %= MOD;
    }

    out(ans);


    return 0;
}



