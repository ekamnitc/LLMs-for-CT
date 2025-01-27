#include<stdio.h>

#define MAX_NUM_OF_PACKS 100000
#define MAX_WEIGHT_OF_A_PACK 10000
#define MAX_TOTAL_WEIGHT MAX_NUM_OF_PACKS * MAX_WEIGHT_OF_A_PACK

int n, k, W[MAX_NUM_OF_PACKS];

bool valid(int p, int ck, int ci) {
  if (ci >= n) return true;
  if (ck >= k || p < W[ci]) return false;

  int tp = p;
  while(tp >= W[ci] && ci < n) {
    tp -= W[ci];
    ci++;
  }

  return valid(p, ck + 1, ci);
}

int minimum(int left, int right) {
  int mid = (left + right) / 2;
  bool result = valid(mid, 0, 0);
  if( mid == left && result) return mid;
  if (result) return minimum(left, mid);
  else return minimum(mid + 1, right);
}

int main() {

  scanf("%d %d", &n, &k);
  for( int i = 0; i < n; i++ ) scanf("%d", &W[i]);

  printf("%d\n", minimum(0, MAX_TOTAL_WEIGHT));
  return 0;
}

