#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>
//#include <boost/multiprecision/cpp_int.hpp>

//namespace mp = boost::multiprecision;
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
//using Bint = mp::cpp_int;

vector<int>A;
vector<int>res;

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int b;
		cin>>b;
		A.push_back(b);
	}
	reverse(A.begin(),A.end());
	for(int i=0;i<N;i++)
	{
		vector<int>nA;
		bool f=false;
		for(int i=0;i<A.size();i++)
		{
			if(!f&&A[i]==A.size()-i)
			{
				f=true;
				res.push_back(A[i]);
			}
			else
			{
				nA.push_back(A[i]);
			}
		}
		if(!f)
		{
			cout<<-1<<endl;
			return 0;
		}
		A=nA;
	}
	reverse(res.begin(),res.end());
	for(auto i:res)cout<<i<<endl;
	
}