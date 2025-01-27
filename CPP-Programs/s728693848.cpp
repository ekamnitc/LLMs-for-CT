#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
const vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T>void debag(const vector<T> &a){cerr<<"debag :";for(auto v:a)cerr<<v<<" ";cerr<<"\n";}
template<class T>void print(const vector<T> &a){for(auto v:a)cout<<v<<" ";cout<<"\n";}
V<V<int>> id(const string &s){
    int n=s.size();
    V<V<int>> num(n+1,V<int>(26,n));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++)num[i][j]=num[i+1][j];
        num[i][int(s[i]-'a')]=i;
    }
    return num;
}
int main(){
    string s;
    cin>>s;
    int n=s.size();
    V<V<int>> num=id(s);
    V<int> dp(n+1,int(1e7));
    V<char> res(n+1,'a');
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++){
            if(num[i][j]==n){
                if(dp[i]>1){
                    dp[i]=1;
                    res[i]=char(j+'a');
                }
            }else{
                if(chmin(dp[i],dp[num[i][j]+1]+1)){
                    res[i]=char(j+'a');
                }
            }
        }
    }
    string ans={};
    int ind=0;
    while(ind<=n){
        ans.push_back(res[ind]);
        ind=num[ind][res[ind]-'a']+1;
    }
    cout<<ans<<"\n";
}