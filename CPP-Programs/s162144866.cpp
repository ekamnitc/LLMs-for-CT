#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, ans = 0; cin>>n;
	for(int i=1;i<=n;i++){
		int c; cin>>c;
		if((i & 1) && (c & 1)) ans++;
	}
	cout<<ans;
}