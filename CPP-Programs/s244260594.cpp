#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, tmp, res = 0;
    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        cin >> tmp;
        res += tmp;
    }

    res = n - res;
    cout << (res < 0 ? -1 : res) << "\n"; 
}