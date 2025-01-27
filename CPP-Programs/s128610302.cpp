#include<iostream>
using namespace std;
int main(){
    int D,T,S;
    cin >> D >> T >> S;
    double time = (double)D / S;
    if(T >= time){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
