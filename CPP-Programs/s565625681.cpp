#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ep emplace_back
#define st first
#define sc second

using namespace std;

const ll mod = 998244353;
const int e = 1e6 + 69;
const int base = 311;

// dung igt thay cho gt luc tinh giai thua
// 3
// cach tao hoan vi tu n so : n*(n+1)/2;

ll a[e];
ll dp[e][27];

int main()
{
    string s;
    cin >> s;
    for(int i=0; i<s.size() - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            cout << i+1 <<" "<<i+2;
            return 0;
        }
    }
    for(int i=0; i<s.size() - 2; i++)
    {
        if(s[i] == s[i+2])
        {
            cout << i+1 <<" "<<i+3;
            return 0;
        }
    }
    cout << - 1 <<" "<< -1;
}
