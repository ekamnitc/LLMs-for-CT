#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   vector<ll>a(3);
    for (int i = 0; i < 3; ++i) {
        cin >>a[i];
    }
   sort(all(a));
   ll ans=0;
   ans+=abs(a[1]-a[0])+abs(a[2]-a[1]);
   cout <<ans <<endl;
   return 0;
}