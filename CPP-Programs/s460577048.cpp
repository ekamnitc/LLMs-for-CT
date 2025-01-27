#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	cin >> n;
  	vector<int> l(n);
  	rep(i, n) cin >> l[i];
  
  	sort(l.begin(), l.end());
  	int ans = 0;
  	rep(b, n){
    	rep(a, b){
          	int ab = l[a] + l[b];
			for(int c = b+1;c < n; c++){
            	if(ab > l[c]) ans++; 
            }
        }
    }
  
  	cout << ans << endl;
}