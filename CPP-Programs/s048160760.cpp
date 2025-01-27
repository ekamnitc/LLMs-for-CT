#include <stdio.h>
#include <string.h>
int main(){
	char a[105],b[105],c[105];
	char l,m,n;
	scanf("%s %s %s" ,&a,&b,&c);
	for(int i = 0; i < strlen(a); i++){
		l = a[i];
	}
	for(int j = 0; j < strlen(b); j++){
		m = b[j];
	}
	for(int k = 0; k < strlen(c); k++){
		n = c[k];
	}
	if(l == b [0] && m == c[0]){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}