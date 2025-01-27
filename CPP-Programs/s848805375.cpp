#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,count1=0,count2=0;

int main(void){
    int n,ans=0,minv=101;
    cin>>n;
    vector<int> vec(n);
    for(i=0;i<n;i++){
        cin>>vec[i];
        ans+=vec[i];
        if(vec[i]%10==0)count1++;
        else{
            minv=min(minv,vec[i]);
        }
    }
    if(count1==n){
        cout<<0<<endl;
        return 0;
    }
    if(ans%10!=0){
        cout<<ans<<endl;
    }else{
        cout<<ans-minv<<endl;
    }
}