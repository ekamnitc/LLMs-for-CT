#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long a[200005];
int main(){
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	long long r=0,ans=0,sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		while(sum1==sum2 && r<=n){
			r++;
			sum1+=a[r];
			sum2^=a[r];
		}
		//cout<<r<<" "<<i<<endl;
		ans+=r-i;
		sum1-=a[i];
		sum2^=a[i];
	}
	
	cout<<ans<<endl;

	return 0;
}