#include <iostream>
#include <algorithm>
#define REP(i,n) for(int i=0; i<n; i++)
using namespace std;

typedef unsigned long ul;
typedef pair<ul, ul> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, h, w;
    cin >> n >> h >> w;
    cout << (n-h+1) * (n-w+1) << '\n';
}
