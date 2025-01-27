#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	rep(i,100000){
		if(i%2 == 0){
			if(a+1 < b) ++a;
			else --a;
			if(a < 1){
				cout << "Borys" << endl;
				return 0;
			}
		}
		else{
			if(b-1 > a) --b;
			else ++b;
			if(n < b){
				cout << "Alice" << endl;
				return 0;
			}
		}
	}
	cout << "Draw" << endl;
	return 0;
}