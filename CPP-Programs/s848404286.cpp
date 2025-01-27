#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin >> S;
    sort(S.begin(),S.end());
    for(int i=1;i<S.size();i++){
        if(S.at(i-1)==S.at(i)){
            cout<<"no"<<endl;
            return 0;
        }
        }
        cout <<"yes"<<endl;
    
}