#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
int dp[301][301][301];
int main()
{
    int i,j;
    string a;
    int k1;
    cin>>a;
    cin>>k1;
    int n=a.size();

            int k;
    for(k=0;k<=k1;k++)
  {

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i+1;j++)
        {
            int o=j+i-1;
            dp[j][o][k]=max(dp[j][o][k],dp[j][o][k-1]);

            if(i==1)
               dp[j][o][k]=1;
               else
               {

                  if(a[j-1]==a[o-1])
                  {

                      dp[j][o][k]=max(dp[j][o][k],dp[j+1][o-1][k]+2);
                  }
                  else{

                    if(k!=0)
                         dp[j][o][k]=max(dp[j][o][k],dp[j+1][o-1][k-1]+2);

                     dp[j][o][k]=max(dp[j][o][k],dp[j+1][o][k]);
                      dp[j][o][k]=max(dp[j][o][k],dp[j][o-1][k]);



                  }



               }



        }


        }




    }






  int ans=0;
  for(k=0;k<=k1;k++)
    for(i=1;i<=n;i++)
    for(j=i;j<=n;j++)

        ans=max(ans,dp[i][j][k]);


    cout<<ans<<endl;
return 0;
}


