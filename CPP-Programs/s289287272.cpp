#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[2][2020];
int main(){
	string s;
	ll ans=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		for(int j=0;j<2019;j++)dp[(i+1)%2][j]=0;
		int k=s[i]-'0';
		dp[(i+1)%2][k]=1;
		for(int j=0;j<2019;j++)dp[(i+1)%2][(j*10+k)%2019]+=dp[i%2][j];
		ans+=dp[i%2][0];
	}
	ans+=dp[s.length()%2][0];//ans累加
	cout<<ans;
	return 0;
}