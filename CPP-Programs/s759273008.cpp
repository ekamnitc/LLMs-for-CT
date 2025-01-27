#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e+15;

int main() {
    int64_t A,B,Q;
    cin >> A >> B >> Q;
    vector<int64_t> s(A+10),t(B+10),x(Q);
    
    for ( int64_t i = 0; i < 5; ++i){
        s[i] = -INF;
        t[i] = -INF;
    }
    for ( int64_t i = 0; i < A; ++i){
        cin >> s[i+5];
    }
    for ( int64_t i = 0; i < B; ++i){
        cin >> t[i+5];
    }
    for ( int64_t i = 0; i < 5; ++i){
        s[i+A+5] = INF;
        t[i+B+5] = INF;
    }
    
    for ( int64_t i = 0; i < Q; ++i){
        cin >> x[i];
    }
    
    /*cout << "-----" ;
    for ( auto p : s ){
        cout << p << " " ;
    }
    cout << "======";*/
    
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    
    for ( int64_t i = 0; i < Q; ++i){
        int64_t pos = x[i];
        auto itrs = lower_bound(s.begin(),s.end(),pos);
        auto itrt = lower_bound(t.begin(),t.end(),pos);
        
        int64_t idxs = itrs - s.begin();
        int64_t idxt = itrt - t.begin();
        
        
        vector<int64_t> ans(6,0);
        int64_t s0,s1,t0,t1;
        s0 = pos - s[idxs-1];
        s1 = s[idxs] - pos;
        t0 = pos - t[idxt-1];
        t1 = t[idxt] - pos;
        //cout << "st " << s0 << " " << s1 << " " << t0 << " " << t1 << endl;
        ans[0] = max(s1,t1);
        ans[1] = max(s0,t0);
        ans[2] = 2 * s1 + t0;
        ans[3] = 2 * s0 + t1;
        ans[4] = 2 * t1 + s0;
        ans[5] = 2 * t0 + s1;
        
        cout << *min_element(ans.begin(),ans.end()) << endl;
        
    }
    
    return 0;
}
