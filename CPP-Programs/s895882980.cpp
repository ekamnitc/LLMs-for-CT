#include<bits/stdc++.h>
using namespace std;
using li = long int;
#define pb push_back

li A, B, GCD, d, i, j;
vector<int> p_factor;

li gcd(li a, li b){
    li x = max(a, b), y = min(a, b);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}

int main(){
    cin >> A >> B;

    p_factor.pb(1);  //確定約数
    GCD = gcd(A, B);
    li d = GCD;
    for(i = 2; i * i <= GCD; i++){
        if(d == 1) break;
        j = 0;
        while(d % i == 0){ d /= i; ++j; }
        if(j > 0) p_factor.pb(i);
    }
  	if(d > 1) p_factor.pb(d);

    cout << (int)(p_factor.size()) << endl;
    return 0;

}