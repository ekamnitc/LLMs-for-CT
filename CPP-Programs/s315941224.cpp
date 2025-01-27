#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define rev(i, n) for(int i = n;i >= 0;i--)
#define Rep(i, m, n) for(int i = m;i < n;i++)
#define repeatrev(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define itn int
const int MAX = 510000;


using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
typedef priority_queue<int> Pr;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    rep(i, s.size() - 8) cout << s[i];
    cout << endl;

}