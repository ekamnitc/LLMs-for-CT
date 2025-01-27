#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
ll a,b,c,d,e,f;

int main(){
    cin >> a >> b >> c >> d >> e >> f;

    set<ll> w,s;
    for(int i=0;i*a<=30;i++){
        for(int j=0;j*b<=30;j++){
            if(i*a+j*b<=30) w.insert(i*a+j*b);
        }
    }
    for(int i=0;i*c<=1500;i++){
        for(int j=0;j*d<=1500;j++){
            if(i*c+j*d<=1500) s.insert(i*c+j*d);
        }
    }

    ll ws=w.size();
    ll ss=s.size();

    pair<ll,ll> ans(make_pair(0,0));
    ld mxmnoudo = 0.0;

    for(auto i:w){
        for(auto j:s){
            //cout << i << " " << j << endl;
            ll wt = i * 100;
            ll sg = j;
            ll sgwt = wt+sg;
            if(e*wt<100*sg) continue;
            if(sgwt>f) continue;
            if(1.0*(ld)(sg)/(ld)(sgwt)>=mxmnoudo){
                mxmnoudo = 1.0*(ld)(sg)/(ld)(sgwt);
                ans = make_pair(sgwt,sg);
            }

        }
    }
    cout << ans.first << " " << ans.second << endl;
}