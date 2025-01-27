#include <bits/stdc++.h>

#define rep(i, s, n) for(int i = (s); i < (int)(n); i++)
#define INF INT_MAX/2

using namespace std;

int N, K;

int main() {
    cin >> N >> K;
 
    queue<int> que1;
    que1.push(1);
 
    rep(i, 0, N) {
        queue<int> que0;
 
        while (!que1.empty()) {
            int x = que1.front(); que1.pop();
            que0.push(x * 2);
            que0.push(x + K);
        }
 
        swap(que1, que0);
    }
 
    int ans = INF;
    while (!que1.empty()) {
        int x = que1.front(); que1.pop();
        ans = min(ans, x);
    }
    cout << ans << endl;
}
