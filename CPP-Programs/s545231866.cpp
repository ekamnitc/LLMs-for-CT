#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int H, W, N;
int ix, iy;
string S, T;

bool solve() {
    // left, right
    int left = 0, right = W;
    if (S[N-1] == 'L') ++left;
    if (S[N-1] == 'R') --right;
    for (int i = N-2; i >= 0; --i) {
        if (T[i] == 'L'){
            right = min(right+1, W);
        }
        else if(T[i] == 'R'){
            left = max(0, left-1);
        }

        if (S[i] == 'L'){
            left = left + 1;
        }
        else if (S[i] == 'R'){
            right = right - 1;
        }

        if (left >= right){
            return false;
        }
    }
    if (iy < left || iy >= right){
        return false;
    }

    // up, down
    left = 0, right = H;
    if (S[N-1] == 'U') ++left;
    if (S[N-1] == 'D') --right;
    for (int i = N-2; i >= 0; --i) {
        if (T[i] == 'U'){
            right = min(right+1, H);
        }
        else if (T[i] == 'D'){
            left = max(0, left-1);
        }

        if (S[i] == 'U'){
            left = left + 1;
        }
        else if (S[i] == 'D'){
            right = right - 1;
        }

        if (left >= right){
            return false;
        }
    }

    if (ix < left || ix >= right){
        return false;
    }

    return true;
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> H >> W >> N >> ix >> iy >> S >> T;
    --ix, --iy;
    if (solve()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
