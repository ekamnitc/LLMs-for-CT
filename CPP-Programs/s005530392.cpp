#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define pb push_back

int main(){
    long long n,k;
    cin>>n>>k;
    int a[200010], b[200010], c[200010];
    int cnt = 0;
    int start = 1;
    int over = 1;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,-1,sizeof(c));
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    b[0] = 1;
    c[1] = 0;
    while (true){
        //cout<<a[b[cnt]]<<" "<<cnt<<" "<<b[cnt]<<endl;
        long long cur = a[b[cnt]];
        if (c[cur] >= 0){
            start = c[cur];
            over  = cnt;
            break;
        }
        cnt++;
        b[cnt] = cur;
        c[cur] = cnt;
    }
    int total = over - start + 1;
    int ex = (k - start +1) % total;
    //cout<<start<<" "<<over<<" "<<ex<<endl;
    if (k <= over){
         cout<<b[k];
    }else{
        if (ex == 0){
            cout<<b[over];
        }else{
            cout<<b[start - 1 + ex];
        }
    }


//    system("pause");
}
