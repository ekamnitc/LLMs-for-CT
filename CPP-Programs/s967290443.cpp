#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
// scanf("%d %d %d %d", &w, &b, &d, &s); %lld
// printf("%d\n", points);
// const double PI = acos(-1);

int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    #else
        fastIO;
    #endif
        int h, w, k, b = 0, ans = 0;
        cin >> h >> w >> k;
        vector<string> v(h);

        for(int i = 0; i<h; i++)
            cin >> v[i];

        for(int i = 0; i<(1<<h); i++){
            for(int j = 0; j<(1<<w); j++){
                for(int n = 0; n<h; n++){
                    for(int m = 0; m<w; m++)
                        if(!(i&(1<<n) || j&(1<<m)))
                            if(v[n][m] == '#') b++;
                }
                if(b==k) ans++;
                b = 0;
            }
        }
        cout << ans << endl;
        return 0;
}
