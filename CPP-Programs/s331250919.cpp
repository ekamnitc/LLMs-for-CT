#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int j,arr[n];
  for(j=0;j<n;j++)
      cin>>arr[j];
  int odd=0;
  for(j=0;j<n;j++)
  {
    if(arr[j]%2!=0)
        odd++;
  }
  if(odd%2==0)
      cout<<"YES"<<endl;
  else
     cout<<"NO"<<endl;
}