#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int N;
    cin >> N;
    int x = 0, y = 0;
    int t_prev = 0;
    rep(i, N)
    {
        int t, p, q;
        cin >> t >> p >> q;
        int n = abs(p-x);
        int m = abs(q-y);
        //if((n+m)==t)
        int d = t-t_prev;
        t_prev = t;
        // if(n==0 && m ==0)
        // {
        //     if(n%2 == 0)
        //     {
        //         x = p; y = q;
        //         continue;
        //     } 
        //     else
        //     {
        //         cout << "No" << endl;
        //         return 0;
        //     }    
           
        // }
        // else
        {
            if(d%(n+m) == 0)
            {
                x = p; y = q;
                continue;
            } 
            else
            {
                cout << "No" << endl;
                return 0;
            }    
        }
        
       
    }
    cout << "Yes" << endl;
    return 0;
}