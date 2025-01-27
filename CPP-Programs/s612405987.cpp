#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> adj;
stack<int> ordering;
vector<bool> vis;

void dfs(int i){
	if(vis[i]) return;
	vis[i]=true;
	for(int j : adj[i]) dfs(j);
	ordering.push(i);
}

int main (){
	cin >> n >> m;
	adj=vector<vector<int>>(n);
	vis=vector<bool>(n,false);
	for(int i=0; i<m; ++i){
		int a,b;
		cin >> a >> b;
		--a;--b;
		adj[a].push_back(b);
	}
	for(int i=0; i<n; ++i) dfs(i);
	vector<int> dp(n,0);
	while(!ordering.empty()){
		int i=ordering.top(); ordering.pop();
		for(int j : adj[i]) dp[j]=max(dp[j], dp[i]+1);
	}
	int ans=0;
	for(int i : dp) ans=max(ans, i);
	cout << ans;
		
	return 0;
}

