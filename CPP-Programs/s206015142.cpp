#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, A, B, a[5050], b[5050];
ll f[5050][5050];

void Umn(auto &x,auto y){
    x=min(x,y);
}

int main(){
    cin>>n>>A>>B;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        b[a[i]]=i;
    }
    memset(f,33,sizeof f);
    f[0][0]=0;
    for (int i=0;i<=n;++i)
        for (int j=0;j<=n;++j){
            if (i<n) Umn(f[i+1][j],f[i][j]+(a[i+1]>j? A: 0));
            if (j<n) Umn(f[i][j+1],f[i][j]+(b[j+1]>i? B: 0));
            if (i<n&&j<n&&a[i+1]==j+1) Umn(f[i+1][j+1],f[i][j]);
        }
    cout<<f[n][n]<<endl;
}