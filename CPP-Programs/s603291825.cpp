#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = s.size();
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	vector<int> is1(26), is2(26);
	rep(i, n) is1[s[i] - 'a']++, is2[t[i] - 'a']++;
	sort(is1.begin(), is1.end());
	sort(is2.begin(), is2.end());
	if (is1 == is2) printf("%s\n", "Yes");
	else printf("%s\n", "No");
	return 0;
}
