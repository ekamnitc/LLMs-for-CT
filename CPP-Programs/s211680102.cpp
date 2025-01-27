#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    if(s[n-1]=='s')s=s+"es";
    else s=s+"s";
    cout<<s;
}