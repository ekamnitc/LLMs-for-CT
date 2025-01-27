#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	map<int,int>m;
	map<int,int>::iterator it;
	while(n--){
		int a;
		cin>>a;
		it = m.find(a);
		if(it!=m.end()) it->second+=1;
		else m.insert(make_pair(a,1));
	}
	vector<long long>stick;
	for(it = m.begin(); it!=m.end(); it++){
		if(it->second>=2) stick.push_back(it->first);
		if(it->second>=4) stick.push_back(it->first);
		sort(stick.begin(),stick.end());
		while(stick.size()>=3) stick.erase(stick.begin()); 
	}
	if(stick.size()<=1) cout<<0;
	else cout<<stick[stick.size()-1]*stick[stick.size()-2];
}