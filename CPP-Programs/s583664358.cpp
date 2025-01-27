#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vec_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define vec_output(v) for(auto it=v.begin();it!=v.end();it++){if(it!=v.begin())cout<<" ";cout<<*it;}cout<<endl;
#define vec_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);
long long int combination(long long int,long long int);
long long int series_sum(long long int);

int main(){
    int n,m,d;
    cin>>n;
    unordered_map<int,int> map1;
    rep(i,n){
        cin>>d;
        if(map1.count(d)){
            map1[d]++;
        }else{
            map1[d]=1;
        }
    }
    cin>>m;
    unordered_set<int> set;
    unordered_map<int,int> map2;
    rep(i,m){
        cin>>d;
        if(map2.count(d)){
            map2[d]++;
        }else{
            set.insert(d);
            map2[d]=1;
        }
    }
    int ans=1;
    for (auto value : set) {
        if(map1[value]<map2[value]){
            ans=0;
            break;
        }
    }
    YN(ans);
}