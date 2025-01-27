#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 10, INF = 1e9 * 1e9 + 10;

int main()
{
    fastInp;

    ll h, w;
    cin >> h >> w;

    if (h == 1 || w == 1) {
        cout << "1";
        return 0;
    }
    cout << (h * w - 1) / 2 + 1;
    
    
    return 0;
}