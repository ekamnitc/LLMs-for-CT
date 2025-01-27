#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;


int main() {
    int h,w;
    cin >> h >> w;
    vector<int> cnt(26,0);
    rep(i,h)rep(j,w){
        char a;
        cin >> a;
        cnt[a -'a'] ++;
    }
    int four = 0,two = 0;
    rep(i,26){
        four += cnt[i]/4;
        cnt[i] %= 4;
        two += cnt[i]/2;
    }

    four -= (h/2) * (w/2);
    if(four < 0){
        cout << "No" << endl;
        return 0;
    }
    two += four * 2;

    if(h%2 ==1) two -= w/2;
    if(w%2 ==1) two -= h/2;

    if(two < 0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    return 0;

    
}