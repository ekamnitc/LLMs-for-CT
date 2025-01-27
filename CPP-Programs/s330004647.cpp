    
#include<bits/stdc++.h>
using namespace std;
int main (){
    int A, C , a,b;
    char o;
    cin >> A>> o>> C;
    if(o == '+'){
        a = A + C;
        cout << a <<endl;
    }
    else{
        a= A - C;
        cout << a <<endl;
    }
    
}