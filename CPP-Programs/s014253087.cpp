#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int pfs[maxn];
int pft[maxn];
signed main() {
    string s,t;
    cin>>s>>t;
    pfs[0]=0;
    for(int i=0 ; i<=s.length() ; i++) {
        if(s[i]=='A') pfs[i+1]=pfs[i]+1;
        else pfs[i+1]=pfs[i]+2;
        //cout<<"pfs "<<i<<" = "<<pfs[i]<<endl;
    }
    pft[0]=0;
    for(int i=0 ; i<=t.length() ; i++) {
        if(t[i]=='A') pft[i+1]=pft[i]+1;
        else pft[i+1]=pft[i]+2;
        //cout<<"pft "<<i<<" = "<<pft[i]<<endl;
    }
    int q;
    cin>>q;
    while(q--) {
        int a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        int s1=pfs[b1]-pfs[a1-1];
        int s2=pft[b2]-pft[a2-1];
        //cout<<s1<<" "<<s2<<endl;
        if(s1%3==s2%3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
