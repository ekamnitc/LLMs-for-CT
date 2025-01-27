#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

int toid(int i,int j,vector<vector<int>> &id){
	if(i>j)
		swap(i, j);
	return id[i][j];
}

//深さ優先探索のテンプレ.デフォルトでは参照渡ししたsetに探索済みの頂点が格納される.
//graphは隣接リスト.vは探索開始地点.seenは空のセット
int dfs(vector<vector<int>> &graph, int v, vector<int> &dp,vector<int> &calc){
	if(dp[v] >= 0){
		if(calc[v] == 0)
			return -1;
		return dp[v];
	}
	dp[v] = 1;

	for (auto nxt:graph[v]){
		int temp = dfs(graph, nxt, dp, calc);
		if (temp == -1)
			return -1;
		dp[v] = max(dp[v], temp+1);
	}
	calc[v] = 1;
	return dp[v];
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> p(n, vector<int>(n - 1));
	vector<vector<int>> a(n, vector<int>(n - 1));
	rep(i,n){
		rep(j, n - 1){
			cin >> p[i][j];
			p[i][j]--;
		}
	}
	int v = 0;
	vector<vector<int>> id(n, vector<int>(n));
	rep(i, n)
	{
		rep(j,n){
			id[i][j] = v;
			v++;
		}
	}
	vector<vector<int>> graph(v);
	rep(i, n)
	{
		rep(j,n-1){
			a[i][j] = toid(i, p[i][j], id);
		}
		rep(j, n - 2)
		{
			graph[a[i][j]].push_back(a[i][j+1]);
		}
	}
	vector<int> dp(v, -1);
	vector<int> calc(v, 0);
	int ans = 0;
	rep(i,v){
		int temp = dfs(graph, i, dp, calc);
		if (temp == -1)
		{
			cout << -1 << endl;
			return 0;
		}
		ans = max(ans, temp);
	}
	cout << ans << endl;

	return 0;
}