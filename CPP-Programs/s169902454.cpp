#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
 int n;
 cin>>n;
 vector<int> v;
 for(int i=0;i<n;i++)
 {
   int x;
   cin>>x;
   v.push_back(x);
 }
 cout<<*max_element(v.begin(),v.end())-*min_element(v.begin(),v.end())<<endl;
}