#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ll n,k;
	cin >> n >> k;
	ll c[100001] = {};
	int a,b;
	for (int i=0;i<n;i++) {
		cin >> a >> b;
		c[a]+=b;
	}
	ll d=0;
	for (int i=0;i<100001;i++) {
		d+=c[i];
		if (d>=k) {
			cout << i;
			return 0;
		}
	}
}