#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;
using Graph = vector<vector<int>>;
int main(){

int h,n;
cin>>h>>n;
int x=0;
for(int i=0;i<n;i++){
    int y;
    cin>>y;
    x+=y;
}
if(x>=h){
    cout<<"Yes"<<endl;
}
else
{
    cout<<"No"<<endl;
}


}