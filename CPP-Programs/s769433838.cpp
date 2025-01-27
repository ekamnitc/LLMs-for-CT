#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    int n;
    cin>>n;
    int d[13]={};
    d[0]++;
    rep(i,n){
        int tmp;cin>>tmp;
        d[tmp]++;
    }
    rep(i,13){
        if(d[i]>=3||d[0]>1){
            cout << 0 << endl;
            return 0;
        }
    }
    DEBUG{cout << "main" << endl;}
    int res=0;
    rep(i,1<<14){
        int restmp=1<<28;
        vector<int> times;
        times.push_back(0);
        times.push_back(24);
        rep(j,13){
            if(j==0){continue;}
            if(d[j]==2){
                times.push_back(j);
                times.push_back(24-j);
            }
            else if(d[j]==1){
                if(i>>j&1){
                    times.push_back(j);
                }else{
                    times.push_back(24-j);
                }
            }
        } 
        sort(times.begin(),times.end());
        rep(j,times.size()-1){
            restmp = min(restmp, times[j+1]-times[j]);
        }
        times.clear();
        res = max(res,restmp);
    }
    cout << res << endl;
    return 0;
}
