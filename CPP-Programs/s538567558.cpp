#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    int h,w;
    cin >> h >> w;
    p_queue(int) pos;
    rp(i,h){
        rp(j,w){
            int t;
            cin >> t;
            if(t&1){
                if(i&1) pos.push((i+1)*w-j-1);
                else pos.push(i*w+j);
            }
        }
    }
    int ctr=0;
    vector<pair<P,P>> ans(0);
    while(!pos.empty()){
        int p=pos.top(); pos.pop();
        if(pos.empty())break;
        int q=pos.top(); pos.pop();
        repi(i,p,q){
            P a,b;
            if((i/w)&1){
                a=mp(i/w+1,w-i%w);
            }
            else a=mp(i/w+1,i%w+1);
            if(((i+1)/w)&1) b=mp((i+1)/w+1,w-(i+1)%w);
            else b=mp((i+1)/w+1,(i+1)%w+1);
            ans.pb(mp(a,b));
            ctr++;
        }
    }
    print(ctr);
    for(auto pp : ans){
        princ(pp.first.first);
        princ(pp.first.second);
        princ(pp.second.first);
        print(pp.second.second);
    }
    return 0;
}