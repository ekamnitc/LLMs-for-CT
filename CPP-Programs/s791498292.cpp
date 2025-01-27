//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    int N,K;
    cin >> N >> K;

    if(((N-1)*(N-2))/2<K){
        cout << -1 << endl;
        return 0;
    }
    int cnt=0;
    bool flag=false;
    cout << ((N-1)*(N-2))/2-K+N-1 << endl;

    REP2(i,2,N+1) cout << 1 << " " << i << endl;
    REP2(i,2,N+1){
        REP2(j,i+1,N+1){
            if(cnt==((N-1)*(N-2))/2-K) flag=true;
            if(flag) break;
            cout << i << " " << j << endl;
            cnt++;
            
        }
        if(flag) break;
    }


    
}