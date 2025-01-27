#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5005;
ll c[maxn], p[maxn], b[maxn], n, k, ans = -999999999999, t, cnt, vis[maxn], inf = 0;
int main()
{
    //freopen("input.in", "r", stdin);
    // cin >> n >> k;
    // for (int i = 1; i <= n; i++)
    //     cin >> p[i];
    // for (int i = 1; i <= n; i++)
    //     cin >> c[i];
    // ll temp;
    // for (int i = 1; i <= n; i++)
    // {
    //     memset(b, 0, sizeof(b));
    //     memset(vis, 0, sizeof(vis));
    //     cnt = 0, temp = 0, t = i, inf = 0;
    //     while (vis[p[t]] == 0)
    //         b[cnt + 1] = c[p[t]], inf += c[p[t]], cnt++, vis[p[t]] = 1, t = p[t];
    //     if (k <= cnt)
    //     {
    //         ll ab = 0;
    //         for (int j = 1; j <= k; j++)
    //         {
    //             ab += b[j];
    //             ans = max(ans, ab);
    //         }
    //         continue;
    //     }
    //     if (inf <= 0)
    //     {
    //         ll ab = 0;
    //         for (int j = 1; j <= cnt; j++)
    //         {
    //             ab += b[j];
    //             ans = max(ans, ab);
    //         }
    //     }
    //     {
    //         int kk = k / cnt;
    //         kk--;
    //         temp = (kk * inf);
    //         ans = max(temp, ans);
    //         for (int j = 1; j <= cnt; j++)
    //         {
    //             temp = temp + b[j];
    //             ans = max(temp, ans);
    //         }
    //         kk++;
    //         for (int j = 1; j <= k - kk * cnt; j++)
    //         {
    //             temp = temp + b[j];
    //             ans = max(temp, ans);
    //         }
    //     }
    // }
    // cout << ans << endl;
    int as;
    cin>>as;
    if(as>=30) puts("Yes");
    else cout<<"No"<<endl;
    return 0;
}