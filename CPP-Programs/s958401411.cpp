#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N){
        cin >> A[i];
    }
    sort(A.rbegin(),A.rend());
    if(N%2==0){
        // N型と逆N型があるが対称なのでN型だけ考える
        // (b-a)+(b-c)+(d-c) = -a + 2b -2c + d
        // 端の係数は-1か1
        // 端以外は-2か2
        // 大きいほうから(N-2)/2取って2かける
        // 次の数はそのまま
        // 次の数を引く
        // 残った(N-2)/2は-2かける
        ll ans = 0;
        for(int i=0; i<(N-2)/2; i++){
            ans += A[i]*2;
        }
        ans += A[(N-2)/2];
        ans -= A[(N-2)/2+1]; // N/2
        for(int i=(N-2)/2+2; i<N; i++){
            ans -= A[i]*2;
        }
        cout << ans << endl;
    }else{
        // 奇数の場合はW型とM型がある
        // W型の時
        // 両端は+1,それ以外のうち(N-2)/2個が+2,残りの(N-2)/2+1が-2
        ll ans1 = 0;
        for(int i=0; i<(N-2)/2; i++){
            ans1 += A[i]*2;
        }
        ans1 += A[(N-2)/2] + A[(N-2)/2+1];
        for(int i=(N-2)/2+2; i < N; ++i){
            ans1 -= A[i]*2;
        }
        // M型の時
        // 両端が-1,それ以外のうち(N-2)/2個が-2,残りの(N-2)/2+1が+2
        ll ans2 = 0;
        for(int i=0; i<(N-2)/2+1; i++){
            ans2 += A[i]*2;
        }
        ans2 -= A[(N-2)/2+1] + A[(N-2)/2+2];
        for(int i=(N-2)/2+3; i < N; ++i){
            ans2 -= A[i]*2;
        }
        cout << max(ans1,ans2) << endl;
    }
    return 0;
}