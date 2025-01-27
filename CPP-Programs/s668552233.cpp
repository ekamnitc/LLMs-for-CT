#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,Q;
string S;
ll cnt[100010];
int main(){
    cin>>N>>Q>>S;
    for(ll i=2;i<=N;i++){
        cnt[i]=cnt[i-1]+(S[i-1]=='C' && S[i-2]=='A');
    }
    for(ll i=0;i<Q;i++){
        ll l,r;
        cin>>l>>r;
        cout<<cnt[r]-cnt[l]<<endl;
    }
    return 0;
}