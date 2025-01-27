#include <stdio.h>
#include <math.h>

int main(void)
{
  long long int N, P, Q, p, k, ans;

  scanf("%lld%lld",&N,&P);

  if(N == 1) {
    printf("%lld\n",P);
    return 0;
  }
  else if (N>=40) {
    printf("%lld\n",1);
    return 0;
  }
  
  ans = 1;
  p = 2;
  while(1) {
    Q = pow(p,N);
    if(P < Q) {
      break;
    } else if(P == Q) {
      ans *= p;
      break;
    }

    k = 0;
    while(P % p == 0) {
        P /= p;
        k ++;
    }
    ans *= pow(p, k/N);
    p += 1;
  }

  printf("%lld\n",ans);
  return 0;
}
