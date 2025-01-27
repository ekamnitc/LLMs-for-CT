#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int most, n;
	int array[101] = {0};
	most = 0;
	while(cin >> n){
		array[n]++;
		if(most < array[n]){
			most = array[n];
		}
	}
	for(int i=1; i<=100; i++){
		if(array[i] == most){
			cout << i << endl;
		}
	}
	return 0;
}