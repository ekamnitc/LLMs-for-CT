#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    cout << (1900 * M + 100 * (N - M)) * (int)pow(2, M) << endl;
    return 0;
}
