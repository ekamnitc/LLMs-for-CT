#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    string  S;
    ll K;
    string ans;
    cin >> S >> K;
    ll count1 = 0;
    rep(i, 0, S.size()){
        if(S[i] == '1') count1++;
        else break;
    }
    if(count1 >= K) cout << "1" << endl;
    else cout << S[count1] << endl;
}