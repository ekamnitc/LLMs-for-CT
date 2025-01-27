#include<bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin>>n;
    int s=n.size();
    int c[s];
    for(int i=0;i<s;i++){
        n[i]-='0';
        c[i]=9-n[i];
    }
    c[s-1]++;
    int dp[s+1][2];
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=0;i<s;i++){
        dp[i+1][0]=min(dp[i][0]+n[i],dp[i][1]+c[i]+1);
        dp[i+1][1]=min(dp[i][0]+n[i]+1,dp[i][1]+c[i]);
    }
    cout<<min(dp[s][0],dp[s][1])<<endl;
    return 0;
}