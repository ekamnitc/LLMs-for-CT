#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<double> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);
    sort(array.begin(),array.end());
    double sum = array.at(0);
    for(int i=1;i<n;i++){
        sum = (sum + array.at(i))/2;
    }
    printf("%.7lf\n",sum);
}