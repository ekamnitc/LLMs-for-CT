#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int N;
vector<vector<int>> E;
int need[100000 + 10];

int getneed(int pos) {
	if (need[pos] != 0)return need[pos];
	vector<int> slist;
	for (int i = 0; i < E[pos].size(); i++) {
		int nxt = E[pos][i];
		slist.push_back(getneed(nxt));
	}
	sort(slist.begin(), slist.end());
	int cnt = 0;
	for (int i = 0; i < slist.size(); i++) {
		if (cnt < slist[i])cnt = slist[i];
		cnt++;
	}
	need[pos] = cnt;
	return need[pos];
}

int main() {
	cin >> N;
	E.resize(N);

	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		a--;
		E[a].push_back(i);
	}

	getneed(0);

	cout << need[0] << endl;

	return 0;
}