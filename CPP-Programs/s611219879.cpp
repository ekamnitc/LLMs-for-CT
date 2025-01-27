#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int have[200010][2];
vector<int> G[200010];
int V;
bool visited[200010];
string S;

void dfs(int i) {
    //cout << i << endl;
    visited[i] = true;
    for(auto to: G[i]) {
        have[to][S[i] - 'A']--;
        if (max(have[to][0], have[to][1]) >= 1 && min(have[to][0], have[to][1]) == 0 && !visited[to]) {
            dfs(to);    
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    cin >> S;
    rep(i, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        have[a][S[b] - 'A']++;
        have[b][S[a] - 'A']++;
    }
    V = N;
    rep(i, N) {
        if (max(have[i][0], have[i][1]) >= 1 && min(have[i][0], have[i][1]) == 0 && !visited[i]) {
            dfs(i);    
        }
    }
    rep(i, N) {
        if (min(have[i][0], have[i][1]) > 0) {
            cout << "Yes" <<endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
