#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    int N;
    cin >> N;

    bool isExists = false;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (i * j == N)
            {
                isExists = true;
                break;
            }
        }
    }
    if (isExists)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}