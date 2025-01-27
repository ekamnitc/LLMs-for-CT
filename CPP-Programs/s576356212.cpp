#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int flag=0;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]==b[a.length()-1-i])
            continue;
        else
            flag=1;
    }
    if(flag==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
