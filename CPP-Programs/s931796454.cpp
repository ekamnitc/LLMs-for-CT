
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 ,s2 , s3 , s ;
    cin>>s1>>s2>>s3;
    vector<char>v;
    v.push_back(s1[0]-32);
    v.push_back(s2[0]-32);
    v.push_back(s3[0]-32);
    cout<<v[0]<<v[1]<<v[2]<<endl;
}