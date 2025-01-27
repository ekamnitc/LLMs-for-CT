#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define MOD (998244353)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> tup;

tup part_value(string &S, ll idx) {
    ll n = 0, m = 0;

    bool next = false;
    
    while(idx < S.length()) {
        if(S[idx] == '>') next = true;
        if(next == true && S[idx] == '<') break;

        if(next) m++;
        else n++;

        idx++;
    }
    // while(S[idx] == '<') {
    //     n++;idx++;
    //     if(idx >= S.length()) {
    //         return make_pair((n*(n+1)/2) + (m*(m+1)/2) - min(n, m), idx);
    //     }
    // }
    // while(S[idx] == '>') {
    //     m++;idx++;
    //     if(idx >= S.length()) {
    //         return make_pair((n*(n+1)/2) + (m*(m+1)/2) - min(n, m), idx);
    //     }
    // }

    return make_pair((n*(n+1)/2) + (m*(m+1)/2) - min(n, m), idx);
}


int main() {
    string S;
    cin >> S;

    ll sum = 0;
    ll idx = 0;

    // for(int i = 0 ; i < 500000; i++) {
    //     S += "<>";
    // }
    //S =  string("<>") ; //+ string(50000, '<') ;

    while(idx < S.length() ) {
        //cout << idx << endl;
        tup t = part_value(S, idx);
        sum += get<0>(t);
        idx = get<1>(t);
    }

    cout << sum << endl;

    return 0;
}