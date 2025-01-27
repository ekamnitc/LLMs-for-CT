#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		string S; cin >> S;
		vector<UL> W(N + 1), B(N + 1);
		rep(i, N) {
			if (S[i] == '.') W[i] = 1;
			else B[i + 1] = 1;
		}
		rep(i, N) {
			B[i + 1] += B[i];
			W[N - i - 1] += W[N - i];
		}
		UL ans = 10000000;
		rep(i, N + 1) {
			ans = min(ans, W[i] + B[i]);
		}
		cout << ans << endl;
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}