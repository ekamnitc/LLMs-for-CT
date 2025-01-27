#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> G[100000];
int n,m;
ll dis[100000][3];


int main()
{
	cin >> n >> m;
	for(int i = 0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
	}
	int s,t;
	cin >> s >> t;
	s--;t--;
	for(int i = 0;i<100000;i++)
	{
		for(int j = 0;j<3;j++)dis[i][j] = -1;
	}
	using P = pair<ll,ll>;
	queue<P> Q;
	Q.emplace(s,0);
	dis[s][0] = 0;
	while(Q.size())
	{
		auto now = Q.front();
		int nken = (now.second+1)%3;
		Q.pop();
		for(auto &i:G[now.first])
		{
			if(dis[i][nken]==-1)
			{
				if(now.second==0)dis[i][nken] = dis[now.first][now.second] +1;
				else dis[i][nken] = dis[now.first][now.second];
				Q.emplace(i,nken);
			}
		}
	}
	cout << dis[t][0] << endl;

}
