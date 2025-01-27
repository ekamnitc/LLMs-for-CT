#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

namespace
{
	bool AnimalCheck(int N, char a0, char a1, const vector<char>& ans)
	{
		vector<char> animal(N+2);
		animal[0] = a0;
		animal[1] = a1;

		for (int i = 1; i <= N; ++i)
		{
			if ((animal[i] == 'S' && ans[i] == 'o') || (animal[i] == 'W' && ans[i] == 'x'))
			{
				animal[i + 1] = animal[i - 1];
			}
			else
			{
				animal[i + 1] = animal[i - 1] == 'W' ? 'S' : 'W';
			}
		}
		bool check = (animal[0] == animal[N]) && (animal[1] == animal[N+1]);
		if (check)
		{
			for (int i = 0; i < N; ++i)
			{
				cout << animal[i];
			}
			cout << endl;
		}
		return check;
	}
}
void ARC069D()
{
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<char> ans(N+1);
	for (int i = 0; i < N; ++i)
	{
		ans[i] = s[i];
	}
	ans[N] = ans[0];

	if (AnimalCheck(N, 'S', 'S', ans))
	{
		return;
	}
	if (AnimalCheck(N, 'S', 'W', ans))
	{
		return;
	}
	if (AnimalCheck(N, 'W', 'S', ans))
	{
		return;
	}	if (AnimalCheck(N, 'W', 'W', ans))
	{
		return;
	}
	cout << -1 << endl;
}

int main()
{
	ARC069D();
	return 0;
}