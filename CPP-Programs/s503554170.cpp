#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
string s,t;
cin>>s>>t;
int ans =t.length();
for(int i=0;i<=s.length()-t.length();i++){
    int diff=0;
    for(int j=0;j<t.length();j++){
        if(t[j]!=s[i+j])
            diff++;
    }
    ans =min(ans,diff);
}
cout << ans << endl;
    return 0;

}
