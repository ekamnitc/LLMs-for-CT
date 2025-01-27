#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    const double PI = acos(-1.0);
    double a, b, h, m;
    cin >> a >> b >> h >> m;

    double r_h = 30.0*h + 30.0/60.0*m;
    double r_m = 6*m;
    double r = abs(r_h - r_m);
    if (r > 180.0) {
        r = 360.0 - r;
    }

    double theta = r / 180.0 * M_PI;

    double ans = sqrt(a*a + b*b - 2.0*a*b*cos(theta));

    cout << std::fixed << std::setprecision(20) << ans << endl;
}
