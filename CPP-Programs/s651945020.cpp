#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;

int main(){
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    if(x > y){ swap(a, b); swap(x, y);}
    cout << min({a*x+b*y, b*(y-x)+2*c*x, 2*c*y}) << "\n";
    return 0;
}