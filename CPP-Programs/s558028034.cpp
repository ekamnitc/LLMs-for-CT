    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    ll n, k, a[200020], f[200020];

    ll check(ll x){
        ll cnt = 0;
        for(ll i = 0; i < n; i++){
            if(a[i]*f[i] <= x) continue;
            ll ki = floor(x*1.0/f[i]);
            //cout << " [ "<<a[i] << " , " << f[i] << " ] "<< (a[i] - ki) << " : " << i <<"    " ;
            cnt += (a[i] - ki);
        }
     //   cout << endl << x << "  " << cnt << endl;
        return (cnt <= k ? 1 : 0);
    }

    void solve() {
        cin >> n >> k;
        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll i = 0; i < n; i++) cin >> f[i];
        sort(a, a + n);
        sort(f, f + n, greater<ll>());
        ll lo = 0, hi = 1e18, m;
        while(lo <= hi){
                //cout << lo << " :: " << hi << endl;
            m = (lo + hi)/2;
            if(check(m)) hi = m-1;
            else lo = m+1;
        }
        cout << max(0ll, (check(hi) ? hi : lo)) << endl;
    }

    int main() {
      cin.sync_with_stdio(0); cin.tie(0);
      cin.exceptions(cin.failbit);
      //ll ti;   cin >> ti;  while(ti--)
      solve();
      return 0;
    }
