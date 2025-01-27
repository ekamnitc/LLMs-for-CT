#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 1000000007
#define LINF 9223372036854775807
#define MOD 1000000007
//#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
//typedef long long int ll;


signed main(){
	int n;
	cin>>n;
	int sum=0,ke;
	for(int i=1;i<=n;i++){
		sum+=i;
		if(sum>=n){
			ke=sum-n;
			n=i+1;
			break;
		}
	}
	for(int i=1;i<n;i++){
		if(i!=ke)cout<<i<<endl;
	}

}