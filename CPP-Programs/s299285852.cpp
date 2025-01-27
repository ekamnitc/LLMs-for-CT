#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 5;
const int logN = 20, BL = 400;
const double EPS = 3e-16;

int main(){
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	long long n; cin >> n;
	vector<long long> a(n);
	for(auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	
	long long first = a.front(), last = a.back(), d = last - first;
	
	if(d > 1) return cout << "No", 0;
	else if(!d){
		if(first == n - 1 || 2 * last <= n) return cout << "Yes", 0;
		else return cout << "No", 0;
	}
	else {
		long long x = 0, y = 0;
		for(auto it : a){
			if(it == first) x++;
			else y++;
		}	
		if(x < last && last <= x + (y / 2)) return cout << "Yes", 0;
		else return cout << "No", 0;
	}	
    
	return 0;
}