#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
string s,t;
int c=0,j=0;
cin >> s >> t;

for (int i = 0 ; i <= s.size() ; i ++){

       if (s[i]!=t[j]){
        c++;
       }
       j++;
}

cout << c << endl;

	return 0;

}
