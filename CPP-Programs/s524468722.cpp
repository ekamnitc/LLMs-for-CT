#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int k = *max_element(all(a));
	vector<int> cnt(k+1);
	for(int i = 0; i < n; i++){
		cnt[a[i]]++;
	}

	bool flag = true;
	if(k%2==0){
		for(int i = 1; i <= k; i++){
			if(i<k/2 && cnt[i]>0) flag = false;
			if(i>k/2 && cnt[i]<2) flag = false;
			if(i==k/2 && cnt[i]!=1) flag = false;
		}
	}else{
		k++;
		for(int i = 1; i <k; i++){
			if(i<k/2 && cnt[i]>0) flag = false;
			if(i>k/2 && cnt[i]<2) flag = false;
			if(i==k/2 && cnt[i]!=2) flag = false;
		}
	}
	
	cout << (flag?"Possible":"Impossible") << endl;

	return 0;
}