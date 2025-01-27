#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(ll i=0;i<n;i++)

#define ll long long
ll mod=1e9+7;
int main(){
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    f(i,n)cin>>a[i+1];
    ll dp[n+1][k+1];
    // memset
    // cout<<"sak";
    f(i,k+1)dp[0][i]=0;
    // f(i,n+1)dp[i][0]=1;
    dp[0][0]=1;

    for(ll i=1;i<=n;i++){
         ll sum[k+1];
            sum[0]=dp[i-1][0]%mod;
            // cout<<sum[0]<<endl;
            for(ll s=1;s<=k;s++){
                sum[s]=(sum[s-1]+dp[i-1][s]%mod)%mod;
                // cout<<sum[s]<<"aSDcsac"<<endl;
            }
        for(ll j=0;j<=k;j++){
            if((j-a[i]-1)>=0){
            dp[i][j]=(sum[j]-sum[(j-a[i]-1)]+mod)%mod;
            }
            else dp[i][j]=sum[j]%mod;
        }
    }
    // cout<<"As";
    // f(i,n+1){
    //     f(j,k+1)cout<<dp[i][j]<<" ";

    //     cout<<endl;
    // }
    cout<<dp[n][k]%mod<<endl;
    return 0;
}
