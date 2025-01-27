#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"GREATER":"LESS")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;

    while (a.size() < b.size()) a = "0" + a;
    while (a.size() > b.size()) b = "0" + b;

    if (a == b) {
        put("EQUAL");
    }
    else if (a < b) {
        put("LESS");
    }
    else {
        put("GREATER")
    }
    return 0;
}