//Om Sree Sai Ram
#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9+7;

void add_self(int&a,int b)
{
  a+=b;
  if(a>=mod)
  {
    a-=mod;
  }
}


int main() 
{


int N;
cin>>N;
string s;
cin>>s;
vector<vector<int>>dp(N+1,vector<int>(N+1));
vector<vector<int>> prefix(N+1,vector<int>(N+1));
// dp[i][j] represents number of ways to fill prefix of size i
// with numbers 1 to i. And the last number filled is j.

dp[1][1] =1;
// if i=1; number of ways to fill it is 1 as 1 can only be filled.

// Now we have to calculte the ways for increasing lengths


for(int i=2;i<=N;i++)
{
  

  for(int j=1;j<i;j++)
  {
    prefix[i-1][j] = (prefix[i-1][j-1]+dp[i-1][j])%mod;

  }

  for(int j=1;j<=i;j++)
  {
    int fill_value = j;
    int L,R;
    //Did'nt understand the logic completely
    if(s[i-2]=='<')
    {
      L = 1;
      R = j-1;
    }
    else
    {
      L = j;
      R = i-1;
    }
    if(L<=R)
    add_self(dp[i][j],(prefix[i-1][R]-prefix[i-1][L-1]+mod)%mod);
    // for(int k=L;k<=R;k++)
    // {
    //   add_self(dp[i][j],dp[i-1][k]);
    // }
    //O(n^3 algorithm) 
    //This understood but am not confident
    // for(int k=1;k<i;k++)
    // {
    //   int true_value = k;
    //   if(k>=j)
    //   {
    //     true_value++;
    //   }

    //   if((true_value<j) != (s[i-2]=='<'))
    //   {
    //     continue;
    //   }

    //   add_self(dp[i][j],dp[i-1][k]);

    // }
  }

}
int ans =0;

for(auto c:dp[N])
{
  add_self(ans,c);
}
cout<<ans<<endl;

}
