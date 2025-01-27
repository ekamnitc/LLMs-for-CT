#include<iostream> 
#include<bits/stdc++.h> 
using namespace std; 
int main()
{
    int n,l,i;
    cin>>n>>l;
    if(n<l)
    for(i=0;i<l;i++)
       cout<<n;
    else
    for(i=0;i<n;i++)
       cout<<l;
    return 0;
}