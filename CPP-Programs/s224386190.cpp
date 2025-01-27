#include<iostream>
using namespace std;
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int fee = n*a;
    if(fee > b){
        cout << b << endl;
    }else{
        cout << fee << endl;
    }
    return 0;
}