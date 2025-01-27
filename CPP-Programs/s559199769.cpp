#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, a[202020];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(a[0] != 0){cout << -1 << endl; return;}
	
	i64 cnt = 0;
	for(int i = n-1; i > 0; i--){
		if(a[i] > a[i-1]+1){
			cout << -1 << endl;
			return;
		}
		cnt += a[i];
		int j = i;
		for(; j > 0; j--){
			if(a[j] != a[j-1]+1) break;
		}
		i = j;
	}
	cout << cnt << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}