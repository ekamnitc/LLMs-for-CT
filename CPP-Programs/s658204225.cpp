#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define pii pair<int, int>
#define LIM 1000
#define MOD 1000000007

string grid[LIM+5];
LL dp[LIM+5][LIM+5];

int main(){
    //freopen("ip.txt", "r", stdin);
    int row, col; cin>>row>>col;
    for(int i = 0; i < row; i++) cin>>grid[i];
    dp[0][0] = 1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == 0 && j == 0) continue;
            if(grid[i][j] == '#') dp[i][j] = 0;
            else if(i == 0) dp[i][j] = dp[i][j-1];
            else if(j == 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
        }
    }
    cout<<dp[row-1][col-1]<<'\n';
}
