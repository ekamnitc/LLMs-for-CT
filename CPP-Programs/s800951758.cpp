#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

int f(int n){
    if(n==0) return 1;
    else return n*f(n-1);
}

int main(void){
    int n;
    cin >> n;
    int x[n],y[n];
    REP(i,n) cin >> x[i] >> y[i];
    vector<int> v(n);
    iota(ALL(v),0);
    long double sum=0;
    do{
        for(int i=0;i<n-1;i++){
            sum+=sqrt((x[v[i]]-x[v[i+1]])*(x[v[i]]-x[v[i+1]]) + (y[v[i]]-y[v[i+1]])*(y[v[i]]-y[v[i+1]]));
        }
    }while(next_permutation(ALL(v)));
    printf("%.7Lf\n",sum/f(n));
    return 0;
}