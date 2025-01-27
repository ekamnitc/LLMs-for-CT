#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
#define PI 3.1415926535
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
bool seen[510][510];
/*void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}*/

//input



//processing




//dpTable
//int dp[100050];
int main(){
    int N,Y;
    cin >> N >> Y;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N - i; j++) {
            int k = N - i - j;
            if ((10000 * i + 5000 * j + 1000 * k) == Y) {
                cout << i << ' ' << j << ' ' << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    return 0;
}