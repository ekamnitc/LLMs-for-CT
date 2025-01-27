#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;



int main(){
    int n; cin >> n;
    vi p(n);
    vi ids(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
        p[i]--;
        ids[p[i]]=i;
    }

    multiset<int> S;
    S.insert(-1), S.insert(-1);
    S.insert(n), S.insert(n);
    ll ans=0;
    for(int i=n-1; i>=0; i--){
        int w, x, y, z;
        auto it1=S.upper_bound(ids[i]);
        auto it2=it1;
        y=*it1, z=*(++it1);
        --it2, x=*it2, w=*(--it2);
        ans+=(ll)(i+1)*((x-w)*(y-ids[i])+(ids[i]-x)*(z-y));
        S.insert(ids[i]);
    }
    cout << ans << endl;
    return 0;
}