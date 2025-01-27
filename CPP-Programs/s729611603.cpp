#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n, m;
	cin >> n >> m;
	int sum = 0;
	vector<int> x(m);
	rep(i , m)
		cin >> x[i];
	pq q;
	sort(x.begin(), x.end());
	rep(i, m - 1)
	{
		q.push(abs(x[i] - x[i+1]));
		sum += abs(x[i] - x[i+1]);
	}
	// cout << sum;
	rep(i, n - 1)
	{
		if (!q.empty())
		{
			sum -= q.top();
			q.pop();
		}
	}
	cout << sum << endl;
	return 0;
}

