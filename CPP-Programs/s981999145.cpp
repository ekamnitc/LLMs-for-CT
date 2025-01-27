#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
int main() {
    int a[6];
    for (int i=0; i<6; i++) {
        cin >> a[i];
    }
    
    string str;
    cin >> str;
    int b,c,d,e;
    b=c=d=e=0;
    for (int i=0; i<str.size(); i++) {
        if(str[i]=='W'){
            
            b=a[0];c=a[2];d=a[3];e=a[5];
            a[3]=b;a[0]=c;a[5]=d;a[2]=e;
        }
        if(str[i]=='N'){
            
            b=a[0];c=a[1];d=a[4];e=a[5];
            a[4]=b;a[0]=c;a[5]=d;a[1]=e;
        }
        if(str[i]=='E'){
            
            b=a[0];c=a[2];d=a[3];e=a[5];
            a[2]=b;a[5]=c;a[0]=d;a[3]=e;
        }
        if(str[i]=='S'){
            b=a[0];c=a[1];d=a[4];e=a[5];
            a[1]=b;a[5]=c;a[0]=d;a[4]=e;
        }
        
    }
    cout << a[0] << endl;
}

