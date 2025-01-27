#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> p(n), a(n), b(n);
    rep(i, 0, n)
    {
        int pp;
        cin >> pp;
        p[--pp] = i + 1;
    } 
        



    ll cumsum = 0;
    rep(i, 0, n)
    {
        cumsum += p[i] - 1;
        a[i] = cumsum + i + 1;
    }
    cumsum = 0;
    rrep(i, n, 0)
    {
        cumsum += p[i] - 1;
        b[i] = cumsum + n - i;
    }
    rep(i, 0, n)
        printf("%ld ", a[i]);
    puts("");
    rep(i, 0, n)
        printf("%ld ", b[i]);
    puts("");
    
    return 0;
}