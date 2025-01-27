#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
LL maximums[85];
int main()
{
int n,array1[100],i;
scanf("%lld",&n);
for(LL i=0;i<n;++i){
    scanf("%lld",&array1[i]);
}
LL money=1000;
for(i=0;i<n-1;++i){
    if(array1[i]<array1[i+1]){
        LL quantity=money/array1[i];
        money+=(array1[i+1]*quantity);
        money-=(quantity*array1[i]);
    }
}
printf("%lld",money);


    return 0;
}
