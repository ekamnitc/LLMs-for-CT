#include<stdio.h>

int main(){
	char s[22];
	scanf("%[^\n]", s);
	for (int i=0 ; s[i]!='\0' ; i++){
		if (s[i]!=','){
			printf ("%c", s[i]);
		} else{
			printf(" ");
		}
	}
	puts("");
	return 0;
}