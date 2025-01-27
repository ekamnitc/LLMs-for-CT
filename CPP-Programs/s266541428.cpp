#include <iostream>
#include <vector>
using namespace std;
int n,m;
bool visited[200010];
void dfs(int v,int depth, vector<vector<int>>& g){
    if(depth == 4) return;
    visited[v] = true;
    for(int nv:g[v]){
        if(visited[nv]) continue;
        dfs(nv,depth+1,g);
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i < n; i++) visited[i] = false;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    dfs(0,1,g);
    if(visited[n-1]) puts("POSSIBLE");
    else puts("IMPOSSIBLE");
    return 0;
}