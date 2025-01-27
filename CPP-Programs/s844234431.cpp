#include<iostream>
#include<string>
using namespace std;


int main(void){
	string str;
	cin>>str;
	int len=str.size();
	for(int i=0;i<len-1;){
		if(str[i]=='S'&&str[i+1]=='T'){
			int temp=i;
			str.erase(i,2);
			if(temp>0)
				i=temp-1;
			else
				i=temp;
			len=str.size();
		}
		else i++;
	}
	cout<<str.size()<<endl;

	return 0;
}