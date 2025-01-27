#include<iostream>
using namespace std;
int main()
{
long long int sum,a,b,c,k;
cin>>a>>b>>c>>k;
if(k<=a) sum=k;
else
{
if(k-a<=b) sum=a;
else sum=2*a-k+b;
}
cout<<sum;
return 0;
}