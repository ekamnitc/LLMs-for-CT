#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

int main() {

    int r,g,b;
    cin >> r >> g >> b;

    int num = r * 100 + g * 10 + b;

    string ans;
    if(num % 4 == 0){
        ans = "YES";
    }else{
        ans = "NO";
    }
    cout << ans << endl;
    return 0;
}