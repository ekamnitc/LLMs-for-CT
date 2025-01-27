#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

vector<long long> bucket(200005,0);

int main(){
    int n;
    cin>>n;
    bucket.resize(n);
    vector<long long> a(n);
    for(int i=0;i<n;++i){
        int temp; cin>>temp;
        --temp;
        a[i]=temp;
        ++bucket[temp];
    }

    long long sum=0;
    for(int i=0;i<n;++i) sum+=bucket[i]*(bucket[i]-1)/2;
    for(int i=0;i<n;++i){
        long long temp=bucket[a[i]];
        long long before=temp*(temp-1)/2;
        long long after=(temp-1)*(temp-2)/2;
        long long ans=sum-before+after;
        cout<<ans<<endl;
    }
}