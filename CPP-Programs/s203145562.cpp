// https://atcoder.jp/contests/abc064/tasks/abc064_d
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int N;
    string S;
    cin >> N >> S;
    int left = 0, x = 0;
    for (int i = 0; i < N; ++i)
    {
        if ('(' == S[i])
        {
            ++left;
        }
        else
        {
            if (left > 0) --left;
            else
            {
                ++x;
            }
            
        }
    }

    string ans;
    for (int i = 0; i < x; ++i)
    {
        ans.push_back('(');
    }
    ans.insert(ans.end(), S.begin(), S.end());
    for (int i = 0; i < left; ++i)
    {
        ans.push_back(')');
    }
    cout << ans << endl;
    return 0;
}
