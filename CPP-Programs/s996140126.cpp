#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
	vector<int> data;
	int sz;

	SegmentTree(int n){
		sz = getsize(n);
		data.assign(4*sz, 0);
	}

	int getsize(int n){
		int i = 0;
		while((1<<i)<=n) i++;
		return (1<<i);
	}

	int add(int k,int x){
		k+=sz-1;
		data[k]+=x;
		while(k){
			k=(k-1)/2;
			data[k] = data[2*k+1] + data[2*k+2];
		}
		
		return 0;
	}

	long long get(int a,int b){
		return _get(a,b,0,0,sz);
	}

	long long _get(int a,int b,int k,int l,int r){
		if(r<=a||b<=l) return 0;
		if(a<=l&&r<=b) return data[k];

		return _get(a,b,2*k+1,l,(l+r)/2) + _get(a,b,2*k+2,(l+r)/2,r);
	}
};

int main(){
	int n, q; cin >> n >> q;
	SegmentTree seg(n);
	
	for(int i=0;i<q;i++){
		int a;
		cin >> a;
		if(a==1){
			int b,c;
			cin >> b >> c;
			cout << seg.get(b-1,c) << endl;
		}else if(a==0){
			int b,c;
			cin >> b >> c;
			seg.add(b-1,c);
		}
	}

	return 0;
}
