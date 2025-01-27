#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

int N;
ll x[100002];

ll dfs(int p, ll c){
    if(N <= p){
        return c;
    }
    if(x[p] == x[p-1] + 1){
        x[p] -= 1;
        //cout << p << " " << c * dfs(p+1, 1) + c * dfs(p+1, c-1) << endl;
        // cout << p << " " << dfs(p+1, 1) << " " << dfs(p+1, c) << endl;
        return (c * dfs(p+1, c)) % MOD;
    }else{
        x[p] = x[p-1] + 2;
        return (c * dfs(p+1, c+1)) % MOD;
    }
}


int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> x[i];
    }

    x[0] = -1;
    x[1] = 1;
    cout << dfs(2, 2) << endl;

    return 0;
}