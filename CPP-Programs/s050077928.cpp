#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

using namespace std;

int main(){
    DRII(k,q);
    VI d(k);
    REP(i,k) RI(d[i]);
    REP(nq,q){
        DRIII(n,x,m);
        n--;
        VI dm(k);
        VL sd(k+1,0);
        VI nb0(k+1,0);
        REP(i,k) {
            dm[i]=d[i]%m;
            sd[i+1]=sd[i]+dm[i];
            nb0[i+1]=nb0[i];
            if (dm[i]==0) {nb0[i+1]++;}
        }
      /*  cout<<"sd"<<endl;
        for (auto i:sd) {cout<<i<<" ";} cout<<endl;
        cout<<"nb0"<<endl;
        for (auto i:nb0) {cout<<i<<" ";} cout<<endl;*/
        LL vf=x+(LL)(n/k)*sd[k] + sd[n%k];
       // cout<<(LL)(n/k)<<" "<<sd[k]<<" "<<(LL)(n/k)*sd[k]<<endl;
        LL nbbp=vf/m-x/m;
        LL nbz=(n/k)*nb0[k] + nb0[n%k];
        LL res=n - nbbp - nbz;
        //cout<<n<<" "<<nbbp<<" "<<nbz<<" "<<vf<<endl;
        printf("%lld\n",res);
    }

}
