#include <bits/stdc++.h>

#define REP(i, s,  n) for(int i = s;i < (n);i++)
#define VSORT(v) sort(v.begin(), v.end());
#define int64 long long
#define pb(a) push_back(a)
#define REP64(i, s,  n) for(int64 i = s;i < (n);i++)
#define INF 999999999
#define MOD 1000000007
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//---------------------------------------------------------------
//---------------------------------------------------------------

string S;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> S;
	int len = S.size();
	int ans;
	char save = '9';
	if(len % 2 == 0) {
		ans = len / 2;
	} else {
		ans = len / 2 + 1;
		save = S[ans - 1];
	}
	REP(i, 1, len) {
		if((len - ans - 1) < 0)	break;
		if(save == '9' && S[ans] == S[len - ans - 1]) {
			save = S[ans];
			ans++;
		} else if(save == S[ans] && save == S[len - ans - 1]) {
			ans++;
		} else {
			break;
		}
	}
	cout << ans << endl;
	
	return 0;
}
