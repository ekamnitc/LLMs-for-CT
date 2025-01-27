#include<bits/stdc++.h>
using namespace std;
#define NL            "\n"
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
int main()
{
    _SAD()
    int n,m;
    cin>>n>>m;
    if(m+n==15)
    {
        cout<<"+"<<NL;
    }
    else if(m*n==15)
    {
        cout<<"*"<<NL;
    }
    else
    {
        cout<<"x"<<NL;
    }
    return 0;
}

