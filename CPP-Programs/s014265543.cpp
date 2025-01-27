#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h, w, n;
	cin >> h >> w >> n;
	
	if(h >= w){
		cout << n / h + (n % h != 0); 
	}
	else{
		cout << n / w + (n % w != 0);
	}
}


