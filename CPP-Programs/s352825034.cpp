 #include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<int,int>;

ll f(ll x,ll c,ll d){
    ll res =x;
    res -=x/c;
    res -=x/d;
    res+= x/lcm(c,d);
    return res;
}

vector<int> to[100005];
const ll inf =100000000;

vector<ll>a,b,c,d;
ll n,m,q;
ll ans=0;
void bfs(vector<ll> v){
   if(v.size()==n+1) {
       ll sum=0;
       rep(i,q){
           if(v[b[i]]-v[a[i]]==c[i])sum+=d[i];
       }
       ans=max(ans,sum);
       return;
   }
   v.push_back(v.back());
   bfs(v);
   while(v.back()<m){
       v.back()++;
       bfs(v);
   }
}

int main(){
 int k;
 cin>>k;
 vector<ll> a;
 for(int i=1;i<=9;++i)a.push_back(i);
 while(1){
     if(k<=a.size()){
         cout<<a[k-1]<<endl;
         return 0;
     }
     k-=a.size();
     vector<ll> old;
     swap(old,a);
     for(ll x:old){
         for(int i=-1;i<=1;i++){
             int d=x%10+i;
             if(d<0||9<d)continue;
             ll nx= x*10+d;
             a.push_back(nx);
         }
     }
 }
}
