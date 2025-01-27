#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,k,n,m,c,t;
    string s;
    cin>>n>>s;c=1;
    for(i=1;i<n;i++){
        if(s[i]!=s[i-1]) c++;
    }
    cout<<c;
}
