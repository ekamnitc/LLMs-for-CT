#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<char,int>;


int main(){
   int n, a, b, c;
   cin >> n >> a >> b >> c;
   vector<int> L(n);
   rep(i, n)cin >> L[i];
   sort(ALL(L));
   ll res = INF;
   //+-1のやつだけもやる必要あり

   do{
       ll cost = 0;
       vector<int> sums(n, 0);
       rep(i, n){
           if(i == 0)sums[i] = L[i];
           else sums[i] = sums[i - 1] + L[i];
       }
       rep(i, n){
           REP(j, i+1, n-1){
               REP(k, j+1, n-1){
                   ll sum_a = sums[i], sum_b = sums[j] - sums[i], sum_c = sums[k] - sums[j];
                   cost = 10 * (k - 2);
                   cost += abs(a - sum_a) + abs(b - sum_b) + abs(c - sum_c);
                   res = min(res, cost);
               }
           }
       }
   }while(next_permutation(ALL(L)));
   cout << res << endl;
}

