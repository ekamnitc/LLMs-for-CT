#include <iostream>
#include <string> 
using namespace std;

       // 最大 200 個なので余裕を持って 210 に --- 200 以上ならなんでもよいです

int main()
{
   string s,t,n,m,min,max;
   int a=0,b=0,i=0,j=0;
   
   cin >> s >> t;
   // for (int i = 0; i < N; ++i) cin >> A[i];
   
   a = s.size();
   b = t.size();
   
   for (i = 0; i < a; ++i) {           
         min[0] = s[i];
           //cout << s[i] << endl;
         for (j = i; j < a; ++j) {
           //cout << s[j] << endl;
            if (s[j] <= min[0]) {
               min[0] = s[j];
               s[j] = s[i];
               s[i] = min[0];
            }  
          } 
   }

   for (i = 0; i < b; ++i) {           
         max[0] = t[i];
           //cout << t[i] << endl;
         for (j = i; j < b; ++j) {
           //cout << t[j] << endl;
            if (max[0] <= t[j] ) {
               max[0] = t[j];
               t[j] = t[i];
               t[i] = max[0];
            }  
          } 
   }

   // cout << s << endl;
   // cout << t << endl;
   if(s < t) cout << "Yes" << endl;
   else cout << "No" << endl;

   return 0;

}