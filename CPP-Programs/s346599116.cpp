#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    cin >> n;
    cin >> s;
    int ans=0;
    // cout << s[2] << s[3] << endl;
    rep(i,n){
        int cnt=0;
        string y="";
        bool w=false;
        for(int j=0;j<i+1;j++){
            // cout << y << endl;
            // cout << j << endl;

            for(int k=i+1;k<n;k++){
                // cout <<j<< k << endl;
                if(s[j]==s[k]){
                    for(int m=0;m<y.size();m++){
                        if(s[j]==y[m]){
                            w=true;
                            break;
                        }
                    }
                    if(w){
                        // cout << "Td" << endl;
                        w = false;
                        break;
                    }
                    else{
                        cnt+=1;
                        // cout << i << j << s[j] << endl; 
                        y+=s[j];
                        break;
                    }
                }
            }
        }
        ans=max(ans,cnt);
    }

    cout << ans;


    return 0;
}