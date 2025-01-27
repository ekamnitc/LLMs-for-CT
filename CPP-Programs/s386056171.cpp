#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

int main()
{

    long long  N,K,ans=0;
    cin >> N>>K;

    for (long long  i = K; i <=N+1; i++)
    {
        long long mi = i*(i-1)/2;
        long long ma = N*(N+1)/2-(N-i)*(N-i+1)/2;
        ans += ma - mi+1;
        ans %= 1000000007;
    }
    cout << ans << endl;
}