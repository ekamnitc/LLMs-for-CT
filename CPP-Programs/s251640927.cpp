#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
struct Nums{
    long long n;
    vector<long long> kaijo;
    Nums(int N){
        n=N;
        kaijo.push_back(0);
        for(long long i=1;i<=n;i++){
            int buf=0;
            int hoge=i;
            while(hoge%2==0){
                hoge/=2;
                ++buf;
            }
            kaijo.push_back((kaijo[i-1]+buf));
        }
    }
    bool comb(long long N,long long K){
        long long res=kaijo[N]-kaijo[K]-kaijo[N-K];
        return res<=0;
    }
};

signed main(){
  int n;cin>>n;
  string s;cin>>s;
  vector<int> a(n);
  Nums lib(n+5);
  bool flag=false;
  rep(i,n){
      a[i]=s[i]-'1';
      if(a[i]==1){
          flag=true;
      }
  }
  if(!flag){
      rep(i,n){
          a[i]/=2;
      }
  }
  int ans=0;
  rep(i,n){
      if(lib.comb(n-1,i)){
          ans+=a[i];
      }
  }
  ans%=2;
  if(!flag)ans*=2;
  cout<<ans<<"\n";

  return 0;
}