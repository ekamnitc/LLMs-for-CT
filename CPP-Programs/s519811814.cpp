#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll a[100200];
ll dp[100200];
vector<int> children[100200];
int parent[100200];
vector<int> path[102000];
void verify(int from){
    for(int i = 0; i < path[from].size(); i++){
        int to = path[from][i];
        if(to == parent[from]) continue;
        parent[to] = from;
        children[from].push_back(to);
        verify(to);
    }
    return;
}

void dfs(int now){
    if(children[now].empty()){
        dp[now] = a[now];
        return;
    }
    ll sum = 0;
    ll maxi = 0;
    for(int i = 0; i < children[now].size(); i++){
        dfs(children[now][i]);
        if(dp[children[now][i]] == -1){
            dp[now] = -1;
            return;
        }
        sum += dp[children[now][i]];
        maxi = max(maxi, dp[children[now][i]]);
    }
    if(children[now].size() == 1){
        if(a[now] == dp[children[now][0]]){
            dp[now] = a[now];
        } else {
            //cout << now << " " << a[now] << " " << children[now][0] << endl;
            dp[now] = -1;
        }
        return;
    }
    //cout << "Searching " << now << endl;
    ll UpperBound = sum;
    ll LowerBound = max((ll)0, 2 * maxi - sum);
    /*if((a[now] > UpperBound) || (a[now] < LowerBound)){
        dp[now] = -1;
        return;
    }
    if((a[now] % 2) != (UpperBound % 2)){
        dp[now] = -1;
        return;
    }*/
    dp[now] = a[now] - (sum - a[now]);
    if((dp[now] > UpperBound) || (dp[now] < LowerBound)){
        dp[now] = -1;
    }
    return;
}

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        parent[i] = 0;
        cin >> a[i];
    }
    parent[1] = 1;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    verify(1);
    for(int i = 1; i <= n; i++){
        //cout << "parent " << i << " " << parent[i] << endl;
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        //cout << dp[i] << endl;
    }
    if(children[1].size() == 1){
        if(dp[1] != -1){
            cout << "YES" << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }
    if(dp[1] == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
