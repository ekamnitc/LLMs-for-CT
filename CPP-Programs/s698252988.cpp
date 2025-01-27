#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;

int main(){
    long long N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;
    if(A>B) swap(A,B);
    bool ok=false;
    REP(m,N+1){
        if(C*(N-1-m)-D*m<=B-A&&B-A<=-C*m+(N-1-m)*D) ok=true;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}