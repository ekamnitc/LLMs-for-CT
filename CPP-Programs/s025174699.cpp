#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
using namespace std;
inline int read()
{
    int x=0,t=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*t;
}
int main() {
    int N; cin >> N;
    multiset<int, greater<int> > Targets;
    vector<int> Slimes;
    for (int i = 0; i < 1 << N; i++) {
        int s; cin >> s;
        Targets.insert(s);
    }
    Slimes.push_back(*Targets.begin());
    Targets.erase(Targets.begin());
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1 << i; j++) {
            multiset<int,greater<int> >::iterator x=Targets.upper_bound(Slimes[j]);
            if (x == Targets.end()) {
                puts("No");
                return 0;
            }
            Slimes.push_back(*x);
            Targets.erase(x);
        }
    }
    puts("Yes");
    return 0;
}