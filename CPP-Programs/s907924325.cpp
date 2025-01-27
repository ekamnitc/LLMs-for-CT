//52行目から編集
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
///////////////////////////////////////////////////////////

const long long INF = LONG_MAX;
long long N,X,ans;
long long x[200020],cum[200020];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(20);
    ans = INF;
    cin >> N >> X;
    rep(i,N)cin >> x[i];
    rep(i,N)cum[i+1] = cum[i] + x[i];
    //cout << INF << '\n';
    for(ll k = 1;k <= N;k++){
        long long res = (k + N) * X;
        ll j = N - 1;
        ll coe = 5;
        while(j >= 0){
            if(coe == 5){
                long long d = cum[j+1] - cum[max(0ll,j - 2*k + 1)];
                if((double)coe > (double)INF / (double)d){
                    res = INF;
                }else{
                    if(d*coe > (INF - res)){
                        res = INF;
                    }else{
                        res += d * coe;
                    }
                }
                coe += 2ll;
                j -= 2*k;
                continue;
            }else{
                long long d = cum[j+1] - cum[max(0ll,j - k + 1)];
                if((double)coe > (double)INF / (double)d){
                    res = INF;
                }else{
                    if(d*coe > (INF - res)){
                        res = INF;
                    }else{
                        res += d * coe;
                    }
                }
                coe += 2ll;
                j -= k;
            }
        }
        ans = min(ans,res);
    }
    cout << ans << '\n';
    return 0;
}
