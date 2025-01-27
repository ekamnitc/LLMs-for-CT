#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,k;
    cin >> n >> k;
    int d;
    int cnt[110]={};
    rep(i,k){
        cin >> d;
        int a[110]={};
        rep(j,d){
            cin >> a[j];
            cnt[a[j]]++;
        }
    }
    
    int ans=0;
    rep2(i,1,n+1){
       if(cnt[i]==0)ans++; 
    }
    
    cout << ans;
    
	return 0;
}