#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <cassert>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main()
{
	ll t1,t2;
	ll a1,a2,b1,b2;
	ll ans=0;
	cin>>t1>>t2;
	cin>>a1>>a2;
	cin>>b1>>b2;
	ll ldif=a2*t2-b2*t2;
	ll fdif=a1*t1-b1*t1;
	if(fdif+ldif==0)
	{
		cout<<"infinity"<<endl;
		return 0;
	}else if((ldif+fdif>0 && fdif>0)||(ldif+fdif<0 && fdif<0)){
		cout<<0<<endl;
		return 0;
	}
	if(fdif+ldif<0)
	{
		ldif*=-1;
		fdif*=-1;
	}
	cerr<<fdif<<" "<<ldif<<" "<<-1*fdif/(fdif+ldif)<<endl;
	//前を求める
	ans+=-1*fdif/(fdif+ldif);
	//後ろ
	ans+=-1*fdif/(fdif+ldif)+1;
	//重複を除く
	if((-1*fdif)%(fdif+ldif)==0)
		ans--;
	cout<<ans<<endl;
	return 0;
}