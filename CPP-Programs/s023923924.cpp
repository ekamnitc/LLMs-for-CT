#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    const int hei = -2;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<string> hai;
    while((n != 1)){
        if(abs(n)%2 == 1){
            hai.push_back("1");
            if(n<0){
                n = n/hei + 1;
            }
            else{
                n = n/hei;
            }
        }
        else{
            hai.push_back("0");
            n = n/hei;
        }
    }
    hai.push_back("1");
    for(int i=hai.size()-1; i>=0; i--){
        cout << hai.at(i);
    }
}
