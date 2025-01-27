#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int q; cin >> q;
	for (int i = 0; i < q; i ++) {
		long long a, b; cin >> a >> b;
		long long root = sqrt(a*b);
		long long ans = root + (a*b-1)/root-1;
		if ((a*b-1)/root >= a) ans --;
		if ((a*b-1)/root >= b) ans --;
		cout << ans << endl;
	}
}