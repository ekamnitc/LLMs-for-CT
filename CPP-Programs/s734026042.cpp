#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

int main()
{
    large n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;

    large x = min({a,b,c,d,e}); // bottle-neck

    large group = (n + x - 1) / x;
    large t = (group - 1) + 5;


    cout << t << endl;
    return 0;
}
