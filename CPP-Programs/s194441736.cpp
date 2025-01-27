#include <bits/stdc++.h>
const int MAXN = 500010;

int n, st[MAXN], col[MAXN], top;
void add() {
	if (st[top] > 1 && st[top - 1] != st[top] - 1) {
		st[top + 1] = st[top];
		col[top + 1] = col[top];
		--st[top]; ++top;
	}
	++col[top];
}
int A[MAXN];
bool judge(int cnt) {
	int lst = 0;
	memset(st, 0, top + 1 << 2);
	memset(col, 0, top + 1 << 2);
	top = 0;
	for (int i = 1, t; i <= n; ++i) {
		t = A[i];
		if (lst < t) {
			if (!top || col[top] != 0) st[++top] = t, col[top] = 0;
			else st[top] = t;
		} else {
			int k = -1;
			while (st[top] > t) k = col[top], --top;
			if (st[top] != t) st[++top] = t, col[top] = k;
			if (cnt > 1) {
				add();
				while (top && col[top] >= cnt) {
					int at = st[top]; --top;
					if (st[top] + 1 != at)
						st[++top] = at - 1;
					add();
				}
			} else top = 0, col[0] = 1;
			if (col[0]) return false;
			if (st[top] != t) st[++top] = t, col[top] = 0;
		}
		lst = t;
	}
	return true;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (judge(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	std::cout << ans << std::endl;
	return 0;
}
