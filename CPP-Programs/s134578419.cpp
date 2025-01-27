#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    int m=a*b;
    int add=a+b-1;
    ans=m-add;
    cout<<ans;
    return 0;
}