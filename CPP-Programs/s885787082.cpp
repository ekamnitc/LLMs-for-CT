#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long
using namespace std;

llint W, H;
vector<pair<llint, int> > vec;

int main(void)
{
	cin >> W >> H;
	int p, q;
	for(int i = 0; i < W; i++){
		cin >> p;
		vec.push_back( make_pair(p, 0) );
	}
	for(int i = 0; i < H; i++){
		cin >> q;
		vec.push_back( make_pair(q, 1) );
	}
	sort(vec.begin(), vec.end());
	
	llint ans = 0;
	llint wcnt = W+1, hcnt = H+1;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].second == 0){
			ans += vec[i].first * hcnt;
			wcnt--;
		}
		else{
			ans += vec[i].first * wcnt;
			hcnt--;
		}
	}
	
	cout << ans << endl;
	return 0;
}