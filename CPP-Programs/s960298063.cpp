#include <bits/stdc++.h>

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORTASC(c) sort((c).begin(),(c).end())
#define SORTDESC(c,t) sort((c).begin(),(c).end(), std::greater<t>());
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define VMAX(a) *max_element(ALL(a))
#define VMIN(a) *min_element(ALL(a))
#define OUT(a) cout << (a) << endl;
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double PI  = acos(-1.0);

template <class T, class S>
using umap = std::unordered_map<T, S>;
using ll = long long;
using namespace std;

int main() {
    string s;

    cin >> s;

    ll year = stoi(s.substr(0, 4));
    ll month = stoi(s.substr(5, 2));
    ll day = stoi(s.substr(8, 2));

    if (year >= 2020){
        cout << "TBD" << endl;
        return 0;
    }

    if (year == 2019) {
        if (month >= 5){
            cout << "TBD" << endl;
            return 0;
        } else if (month == 4){
            if (day > 30){
                cout << "TBD" << endl;
                return 0;
            }
        }
    }

    cout << "Heisei" << endl;

    return 0;
}