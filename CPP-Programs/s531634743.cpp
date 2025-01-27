#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int i,j,a[300],b[300],c[300],len;
	string str1,str2;
	cin>>str1>>str2;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(b));
	if(str2[0]=='0'&&str2[2]=='0'&&str2[3]=='0')
	cout<<"0"<<endl;
	else{
		a[0]=str1.length();
		for(i=1;i<=a[0];i++)
		a[i]=str1[a[0]-i]-'0';
		
		if(str2[0]!='0'&&str2[2]=='0'&&str2[3]!='0'){
			b[1]=str2[3]-'0';
			b[2]=str2[2]-'0';
			b[3]=str2[0]-'0';
			b[0]=3;
		}
		else{
			b[0]=0;j=1;
			for(i=1;i<=2;i++){
				
				if(str2[4-i]-'0'!=0){
					b[j]=str2[4-i]-'0';
					b[0]++;
					j++;
				}
			}
			if(str2[0]!='0'){
				b[j]=str2[0]-'0';
				b[0]++;
			}
		}
		for(i=1;i<=a[0];i++){
			for(j=1;j<=b[0];j++){
				c[i+j-1]=c[i+j-1]+a[i]*b[j];
				c[i+j]=c[i+j]+c[i+j-1]/10;
				c[i+j-1]=c[i+j-1]%10;
			}
		}
		len=a[0]+b[0]+1;
		while((c[len]==0)&&len>1)
		len--;
		if(len<=2)
		cout<<"0"<<endl;
		else{
			if(b[0]==2&&str2[0]-'0'!=0){
			for(i=len;i>=2;i--)
			cout<<c[i];
			cout<<endl;
		}
		else if(b[0]==2&&str2[0]-'0'==0){
			for(i=len;i>=3;i--)
			cout<<c[i];
			cout<<endl;
		}
		else if(b[0]==3){
			for(i=len;i>=3;i--)
			cout<<c[i];
			cout<<endl;
		}
		else if(b[0]==1&&str2[3]-'0'!=0){
			for(i=len;i>=3;i--)
			cout<<c[i];
			cout<<endl;
		}
		else if(b[0]==1&&str2[2]-'0'!=0){
			for(i=len;i>=2;i--)
			cout<<c[i];
			cout<<endl;
		}else if(b[0]==1&&str2[0]-'0'!=0){
			for(i=len;i>=1;i--)
			cout<<c[i];
			cout<<endl;
		}
		}
		
	}

}