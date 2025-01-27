#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef map<pair<int, int>, ll> mpi;

long shUtils(int cnt, int curr, int a[], int n, mpi &dp) {
    
    if (cnt >= n/2) {
        return 0;
    }

    if (curr >= n) {
        return LONG_MIN;
    }

    if (n/2-cnt > (n-curr+1)/2)
    	return LONG_MIN;

    pair<int, int> p = {cnt, n/2-curr};

    if (dp.find(p) != dp.end()) {
    	// deb(dp[p]);
        return dp[p];
    }

    ll tmp = shUtils(cnt + 1, curr + 2, a, n, dp);
    ll choice1;

    if (tmp == LONG_MIN)
        choice1 = tmp;
    else
        choice1 = a[curr] + tmp;

    ll choice2 = shUtils(cnt, curr + 1, a, n, dp);

    ll ans = max(choice1, choice2);
    dp[p] = ans;

    return ans;
}

ll selectHalf(int a[], int n) {

    mpi dp;

    ll ans = shUtils(0, 0, a, n, dp); // cnt and index passed
    return ans;
}

int main() {

	IOS

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << selectHalf(a, n) << endl;

	return 0;
}