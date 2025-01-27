#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979

int  main()
{
	string s[3];
	rep(i, 3)
		cin >> s[i];
	map<char, int> mp;
	mp['a'] = 0; mp['b'] = 1; mp['c'] = 2;
	vector<queue<char> > q(3);
	rep(i, 3)
	{
		rep(j, s[i].size())
		{
			q[i].push(s[i][j]);
		}
	}
	char f = s[0].front();
	q[0].pop();
	char tmp;
	while (1)
	{
		if (!q[mp[f]].empty())
		{
			tmp = q[mp[f]].front();
			q[mp[f]].pop();
		}
		f = tmp;
		if (q[mp[f]].empty())
		{
			char ans = 'A' + mp[f];
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}
