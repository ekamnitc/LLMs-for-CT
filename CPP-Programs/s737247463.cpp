//HovalHaq!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int ll

const int maxN = 1 << 17, INF = 1 << 30;

ll n;
int A[maxN], B[maxN], S[maxN], F[maxN << 1];

void add(int id) {
//	cout << "ADD " << id << endl;
	id += maxN;
	for(; id < 2 * maxN; id += id & -id) F[id]++;
}

int get(int id) {
//	cout << "GET " << id << endl;
	id += maxN;
	int s = 0;
	for(; id; id -= id & -id) s += F[id];
	return s;
}

bool check(int x) {
//	cout << "CHK " << x << endl;
	for(int i = 0; i < n; i++) if(A[i] >= x) B[i] = -1;
	add(0);
	int r = 0;
	for(int i = 0; i < n; i++) {
		S[i + 1] = S[i] + B[i];
		r += get(S[i + 1] - 1);
		add(S[i + 1]);
	}
	for(int i = 0; i < n; i++) B[i] = 1;
	for(int i = 0; i < 2 * maxN; i++) F[i] = 0;
//	cout << r << endl;
	return (r > n * (n + 1) / 4);
}

int32_t main() {
	//Input
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
		B[i] = 1;
	}

	//Solve
	int l = 0, r = INF;
	while(l + 1 < r) {
//		cout << l << " " << r << endl;
		int m = (l + r) >> 1;
		if(check(m)) r = m;
		else l = m;
	}

	//Output
	cout << l;
	return 0;
}
