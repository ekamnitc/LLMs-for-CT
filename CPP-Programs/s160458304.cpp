#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=2e5;
P ps[L];
int main() {
	int H,W,N;
	cin >> H >> W >> N;
	for(int i=0;i<N;i++){
		int x,y;
		cin >> x >> y;
		ps[i]=P(x,y);
	}
	sort(ps,ps+N);
	int d=0;
	for(int i=0;i<N;i++){
		if(ps[i].first-ps[i].second<=d){
			d=max(d,ps[i].first-ps[i].second+1);
		}
		else{
			cout << ps[i].first - 1<< endl;
			return 0;
		}
	}
	cout << H << endl;

	return 0;
}

