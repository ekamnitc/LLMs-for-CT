#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

   int n,m;
   cin>>n>>m;
   int l[m],r[m];
   for(int i=0;i<m;i++)
    cin>>l[i]>>r[i];
   int mn=*max_element(l,l+m);
   int mx=*min_element(r,r+m);
   if(mx>=mn)
    cout<<mx-mn+1<<endl;
   else
    cout<<0<<endl;

}



