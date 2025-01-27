#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >>N;
    int num = N +(N+1)%2;
    int M = (N*(N-1))/2 -N/2;
    cout << M << endl;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(i+j != num){
                cout << i << " "<<j<<endl;
            }
        }
    }
}