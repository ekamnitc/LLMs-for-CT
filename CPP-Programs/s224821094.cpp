#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
 
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};
 
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N,M;
int a[2000],b[2000];
int c[2000][2000]; 

int dp[2000][6000];
int ans=INF;

void init(){
    for(int i=0;i<2000;++i)for(int j=0;j<6000;++j)dp[i][j]=INF;
}

signed main(){
    init();
    cin>>N>>M;
    for(int i=0;i<M;++i){
        cin>>a[i]>>b[i];
        for(int j=0;j<b[i];++j){
            cin>>c[i][j];
            c[i][j]--;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<M;++i){
        for(int j=0;j<(1<<N)-1;++j){
            chmin(dp[i+1][j],dp[i][j]);
            int nj=j;
            for(int k=0;k<b[i];++k){
                if((j>>c[i][k])&1)continue;
                nj+=(1<<c[i][k]);
            }
            chmin(dp[i+1][nj],dp[i][j]+a[i]);
        }
    }
    for(int i=0;i<=M;++i){
        chmin(ans,dp[i][(1<<N)-1]);
    }
    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
}
