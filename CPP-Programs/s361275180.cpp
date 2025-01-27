#include<iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main(){
    string s;
    int ans = 0;
    int num = 0;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'g'){
            if(num < 0 ){
                ans++;
                num++;
            }else{
                num--;
            }
        }else {
            if(num < 0 ){
                num++;
            }else{
                ans--;
                num--;
            }
        }
    }
    cout << ans << endl;
}