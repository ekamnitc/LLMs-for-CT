#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<set<pair<int,int64_t>>> G(N);
    rep(i,0,N-1){
        int a,b;
        int64_t c;
        cin>>a>>b>>c;
        a--; b--;
        G.at(a).insert(make_pair(b,c));
        G.at(b).insert(make_pair(a,c));
    }
    int Q,K; cin>>Q>>K;
    K--;
    vector<pair<int,int>> Pass;
    rep(i,0,Q){
        int x,y; cin>>x>>y;
        x--; y--;
        Pass.emplace_back(x,y);
    }

    vector<int64_t> Cost(N,-1);
    Cost.at(K)=0;

    queue<int> q;
    q.push(K);

    while(!q.empty()){
        int n=q.front(); q.pop();

        for(auto g:G.at(n)){
            if(Cost.at(g.first)>=0) continue;

            Cost.at(g.first)=Cost.at(n)+g.second;
            q.push(g.first);
        }
    }

    for(auto p:Pass){
        int64_t ans=Cost.at(p.first)+Cost.at(p.second);
        cout<<ans<<endl;
    }
}