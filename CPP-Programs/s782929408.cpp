#include <stdio.h>
#include <string.h>
#include <math.h>
int mini(int a, int b){
    if (a>=b) return b;
    else return a;
}
int main ()
{
    int c=0, c2=0;
    char s[100005];
    scanf ("%s", s);
    for (int i=1;i<strlen(s);i=i+1) {
        if (s[0]=='0') {
            if (i%2==1 && s[i]=='0') c++;
            else if (i%2==0 && s[i]=='1') c++;
        }
        else {
            if (i%2==1 && s[i]=='1') c++;
            else if (i%2==0 && s[i]=='0') c++;
        }
    }

    for (int i=strlen(s)-1;i>=0;i=i-1) {
            if (strlen(s)%2==1) {

        if (s[strlen(s)-1]=='0') {
            if (i%2==1 && s[i]=='0') c2++;
            else if (i%2==0 && s[i]=='1') c2++;
        }
        else {
            if (i%2==1 && s[i]=='1') c2++;
            else if (i%2==0 && s[i]=='0') c2++;
        }
    }

    else {
        if (s[strlen(s)-1]=='0') {
            if (i%2==1 && s[i]=='1') c2++;
            else if (i%2==0 && s[i]=='0') c2++;
        }
        else {
            if (i%2==1 && s[i]=='0') c2++;
            else if (i%2==0 && s[i]=='1') c2++;
        }
    }

    }

    printf ("%d", mini(c, c2));
    return 0;
}
