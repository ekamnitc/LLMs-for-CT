#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<long long> DP;
const long long inf = (long long)1e9 + 7;

int popcount(uint32_t a)
{
	int counter = 0;
	while (a != 0)
	{
		if (a & 1)
			counter++;
		a= a >> 1;
	}
	return counter;
}

int main()
{
	cin >> n;
	adj.resize(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		adj[i].resize(n + 1);
		for (int j = 1; j < n + 1; j++)
			cin >> adj[i][j];
	}
	// bit mask DP, iterate through the men one by one (for matching) and use a mask to record which women are available
	// current state, remaining women are recorded in the mask
	// DP[mask], mask 0 ... 2^(n)-1 aruond 4mil
	DP.resize(1 << (n));
	DP[0] = 1; // no women are available, all men are matched

	for (int mask = 1; mask < (1 << n); mask++)
	{
		int a = n+1-popcount(mask);  // number of women remaining, should be matching number of men remaining, also remember we are doing men sequentially
		for (int b = 1; b < n + 1; b++) // scan through women to match with a
		{
			if (adj[a][b] == 1 && mask >> (b - 1) & 1) // a is connected to b; b is available
			{
				//cout << "matching " << a << " to " << b << endl;
				//cout << " mask " << mask << endl;
				//cout << " DP[mask] " << DP[mask] << endl;
				//cout << " mask & (!(1 << (b - 1))) " << (mask & (~(1 << (b - 1)))) << endl;
				DP[mask] = (DP[mask]+DP[mask & (~(1 << (b - 1)))])%inf;
				//cout << DP[mask] << endl;
			}
		}
	}
	cout << DP[(1 << n) - 1] << endl;
}
