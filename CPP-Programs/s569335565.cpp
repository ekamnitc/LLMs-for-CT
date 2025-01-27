#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const long inf=1e9;
int main(){
	int N,K;cin>>N>>K;
	long X[N+1],Y[N+1]; X[0]=0; Y[0]=0;
	map<long,map<long,int>> cnt;
	rep(i,1,N+1){
		cin>>X[i]>>Y[i]; X[i]+=inf; Y[i]+=inf;
		cnt[X[i]][Y[i]]++;
	}
	sort(X,X+N+1); sort(Y,Y+N+1);
	rep(i,1,N+1)rep(j,1,N+1){
		long x=X[i],y=Y[j];
		cnt[x][y]+=cnt[X[i-1]][y]+cnt[x][Y[j-1]]-cnt[X[i-1]][Y[j-1]];
	}
	long ans=4e18;
	rep(i,1,N+1)rep(j,1,N+1){
		rep(k,i+1,N+1)rep(l,j+1,N+1){
			int temp=cnt[X[k]][Y[l]]-cnt[X[i-1]][Y[l]]-cnt[X[k]][Y[j-1]]+cnt[X[i-1]][Y[j-1]];
			if(temp>=K) ans=min(ans,(X[k]-X[i])*(Y[l]-Y[j]));
		}
	}cout<<ans<<endl;
}