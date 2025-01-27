#include <iostream>
using namespace std;

int a, b, c;

void solve() {
    cin >> a >> b >> c;
    cout << (c - (a - b) <= 0 ? 0 : c - (a - b)) << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}