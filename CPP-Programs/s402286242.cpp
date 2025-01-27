#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<string,int>;

int main() {
    int N; cin>>N;
    string S; cin>>S;
    for (int i = 0; i < S.size(); i++){
        cout<<(char)(((int)S[i]-(int)'A'+N)%26+(int)'A');
    }
    cout<<endl;
}