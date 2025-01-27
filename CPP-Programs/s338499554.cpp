#include<iostream>
#include<string>
#include<algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef int status;
typedef long long ll;
typedef unsigned long long ull;
const ull base = 343;
const int INF = int(1e9);
const ll INF1 = ll(1e18);
const int MAX = 200002;

ll N,C;
ll x[MAX],v[MAX];
ll sum1[MAX],sum2[MAX];
ll var1[MAX],var2[MAX];
ll max1 = 0;

int main()
{
    cin>>N>>C;
    for(int i = 1;i <=N;i++)cin>>x[i]>>v[i];
    for(int i = 1;i <= N;i++){
        sum1[i] = sum1[i-1]+v[i];
        var1[i] = max(var1[i-1],sum1[i]-x[i]);
        max1 = max(var1[i],max1);
    }
    for(int i = N;i >= 1;i--){
        sum2[i] = sum2[i+1]+v[i];
        var2[i] = max(var2[i+1],sum2[i]-(C-x[i]));
        max1 = max(var2[i],max1);
    }
    for(int i = N;i >= 1;i--){
        max1 = max(max1,var2[i]+var1[i-1]-(C-x[i]));
    }
    for(int i = 1;i <= N;i++){
       max1 = max(max1,var1[i]+var2[i+1]-x[i]);
    }
    cout<<max1<<endl;
    return 0;
}
