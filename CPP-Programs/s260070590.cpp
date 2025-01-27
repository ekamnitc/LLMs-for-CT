#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    vector<long long> a(3);

    for(long long i = 0 ; i < 3 ; i++) {

        cin >> a[i];

    }

    if(accumulate(a.begin(),a.end(),0LL)>=22) {

        cout << "bust" << '\n';

    } else {

        cout << "win" << '\n';

    }

    return 0;

}

