#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	int H, W; cin >> H >> W;
	vector<vector<char>> S(H, vector<char>(W));
	rep(i, H) {
		rep(j, W)cin >> S[i][j];
	}

	// 縦横それぞれで照らせるマスの数を保存
	vector<vector<int>> yoko(H, vector<int>(W));
	rep(i, H) {
		int head = 0;
		rep(j, W) {
			if (S[i][j] == '#') {
				rep2(k, head, j)yoko[i][k] = (j - head);
				head = j + 1;
			}
			else if (j == W - 1) {
				rep2(k, head, j + 1)yoko[i][k] = (j + 1 - head);
			}
		}
	}
	/*rep(i, H) {
		rep(j, W) {
			cout << yoko[i][j] << " ";
		}
		cout << endl;
	}*/

	vector<vector<int>> tate(H, vector<int>(W));
	rep(j, W) {
		int head = 0;
		rep(i, H) {
			if (S[i][j] == '#') {
				rep2(k, head, i)tate[k][j] = (i - head);
				head = i + 1;
			}
			else if (i == H - 1) {
				rep2(k, head, i + 1)tate[k][j] = (i + 1 - head);
			}
		}
	}
	/*cout << endl;
	rep(i, H) {
		rep(j, W) {
			cout << tate[i][j] << " ";
		}
		cout << endl;
	}*/
	int ans = 0;
	rep(i, H) {
		rep(j, W) {
			int num = yoko[i][j] + tate[i][j] - 1;
			if (ans < num)ans = num;
		}
	}
	cout << ans;
}