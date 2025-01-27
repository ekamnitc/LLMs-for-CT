#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
bool kebalik=0;
ll q, rivers=0;
string s;

int main(){
	IOS
	cin >> s >> q;
	while(q--){
		string a, b, c;
		cin >> a;
		if(a=="1"){
			rivers++;
			if(kebalik){
				kebalik=0;
			}
			else{
				if(s.size()>1) kebalik=1;
			}
		}
		else{
			cin >> b >> c;
			if(b=="1"){
				if(!kebalik){
					s.insert(0, c);
				}
				else{
					s+=c;
				}
			}
			else{
				if(!kebalik){
					s+=c;
				}
				else{
					s.insert(0, c);
				}
			}
		}
	}
	if(rivers&1){
		reverse(s.begin(), s.end());
	}
	cout << s << '\n';
}
