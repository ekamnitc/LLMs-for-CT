#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
llint a[100005];
vector<llint> comp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) comp.push_back(a[i]);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 1; i <= n; i++) a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
	
	llint ans = 0;
	for(int i = 1; i <= n; i+=2){
		if(a[i] % 2 == 0) ans++;
	}
	cout << ans << endl;
	
	return 0;
}