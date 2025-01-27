#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define l first
#define r second

int n, a, b;
vector<int> q;

vector<int> gen()
{
    q.resize(0);
    for (int i = 1; i <= a; i++)
    {
        q.push_back(i);
    }
    vector<int> ans(n + 1);
    for (int k = 0; k <= n - a; k++)
    {
        int cnt = k + 1 + (n - k - 1) / a;
        if (cnt == b)
        {
            //cout << k << endl;
            for (int j = n - a + 1, keklol = 1; j + a >= 1; j -= a)
            {
                for (int i = 0; i < a; i++)
                {
                    if (j + i > k)
                        ans[j + i] = keklol++;
                }
            }
            for (int i = 1; i <= k; i++) ans[i] = n - i + 1;
            return ans;
        }
    }
    return {};
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    if (a + b > n + 1 || 1LL * a * b < n)
    {
        cout << -1;
        return 0;
    }
    vector<int> t = gen();
    swap(a, b);
    vector<int> g = gen();
    if (t.size() != 0)
    {
        for (int i = 0; i < n; i++) cout << t[i + 1] << " ";
    }
    else if (g.size() != 0)
    {
        for (int i = 0; i < n; i++) cout << n + 1 - g[i + 1] << " ";
    }
}