#include <bits/stdc++.h>
using namespace std;
int s[3];

int main() {
    char ch=getchar();
    while (ch>='a' && ch<='c') {
        s[ch-'a']++;
        ch=getchar();
    }
    sort(s,s+3);
    s[1]-=s[0],s[2]-=s[0],s[0]=0;
    if (s[1]>1 || s[2]>1) puts("NO");
    else puts("YES");
    return 0;
}