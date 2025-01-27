#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i,s,e) for( i=s;i<e;i++)
#define rfo(i,s,e) for(i=s;i>e;i--)
#define LLI long long int
#define LI long int 
const LI MOD=1e9+7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//            When something is important enough, you do it even if the odds are not in your favor.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // code goes here
    int t1=1;//cin>>t;
    while(t1--){
      string s,t;cin>>s>>t;
      LI sl=s.length(),tl=t.length(),i;
      std::vector<LI> v[26];
      fo(i,0,sl){
        v[s[i]-'a'].pb(i);
      }
      LI num=0,prev=INT_MAX;
      fo(i,0,tl){
        if(v[t[i]-'a'].size()==0) {cout<<-1;return 0;}
        LI in=lower_bound(v[t[i]-'a'].begin(), v[t[i]-'a'].end(),prev)-v[t[i]-'a'].begin();
        if(in<v[t[i]-'a'].size()&&v[t[i]-'a'][in]==prev) in++;
        if(in>=v[t[i]-'a'].size()) in=0,num++;
        prev=v[t[i]-'a'][in];
      }
      num--;
      cout<<num*sl+prev+1;
    }
    return 0;
}