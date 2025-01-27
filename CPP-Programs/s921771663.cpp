#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
const LL LLINF = 1e16;

int G[500][500];

void rec(int x, int y, int l){
    // cout << x << " " << y << endl;
    if(x == y) return;
    if(x+1 == y){
        G[x][y] = l;
        G[y][x] = l;
    }
    else{
        int mid = (x+y)/2;
        REP(i, x, mid+1){
            REP(j, mid+1, y+1){
                G[i][j] = l;
                G[j][i] = l;
            }
        }
        rec(x, mid, l+1);
        rec(mid+1, y, l+1);
    }
}


int main(){
    int n;
    cin >> n;
    rec(0, n-1, 1);
    rep(i, n){
        REP(j, i+1, n) cout << G[i][j] << (j == n-1 ? "\n":" ");
    }







}