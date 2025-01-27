#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int i=0;
    vector<pair<int,int>>vp;
    while(i<v.size()){
        int prev=v[i];
        int count=0;
        while((i<n)&&(prev==v[i]))
        {
            i++;
            count++;
        }
        vp.push_back({count,prev});
    }
    sort(vp.begin(),vp.end());
    int count=0;
    for(auto it=vp.rbegin();it!=vp.rend();it++)
    {
        if(k>0)
        count+=it->first;
        else
        break;
        k--;
    }
    cout<<n-count;
}