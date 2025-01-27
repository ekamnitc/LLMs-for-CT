#include <bits/stdc++.h>
using namespace std;

const string YES = "YES";
const string NO = "NO";

void solve(long long A, long long V, long long B, long long W, long long T){
  string ans = (abs(A-B) > T * (V-W)) ? NO : YES;
  cout << ans << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long V;
    scanf("%lld",&V);
    long long B;
    scanf("%lld",&B);
    long long W;
    scanf("%lld",&W);
    long long T;
    scanf("%lld",&T);
    solve(A, V, B, W, T);
    return 0;
}
