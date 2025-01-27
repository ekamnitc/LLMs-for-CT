#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    string str;
    cin>>str;
    long long i,a[str.size()],cnt=0,sum=0;
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='B')
        {
            cnt++;
        }
        a[i]=cnt;
    }
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='W')
        {
            sum=sum+a[i];
        }
    }
    cout<<sum;
    return 0;
}