#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int luca0=2, luca1=1;
    int64_t ans=0, temp1=2, temp2=1;
    for(int i=2; i<=n; ++i){
        ans = temp1+temp2;
        temp1 = temp2;
        temp2 = ans;
    }

    if(n==0) ans=2;
    if(n==1) ans=1;

    cout << ans << endl;
}