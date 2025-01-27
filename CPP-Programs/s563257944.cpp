#include <stdio.h>

int main(){
  int n, q;
  scanf("%d%d", &n, &q);
  char s[200001];
  scanf("%s", s);
  char t[200001], d[200001];
  for(int i=0; i<q; i++){
    scanf(" %c %c", &t[i], &d[i]);
  }

  /* 改良 */
  int count=0;
  int count2=0;
  int r=n-1;

  /* 呪文の実行 */
  for(int i=q-1;i>=0;i--){
    if(d[i] == 'R'){
      if (s[count-1] == t[i]) {
        count--;
      }
      if(s[r] == t[i]){
        r--;
      }
    }else if(d[i] == 'L'){
      if(s[r+1] == t[i]) {
        r++;
      }
      if(s[count] == t[i]) {
        count++;
      }
    }
  }

  if(r < 1){
    count2 = 0;
  }else{
    count2 = r-count+1;
  }

  printf("%d\n",count2);
  return 0;
}
