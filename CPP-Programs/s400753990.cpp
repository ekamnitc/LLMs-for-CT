//
// Created by 李青坪 on 2018/10/26.
//

#include <cstdio>

using namespace std;
#define MAXN 500001
int heaps[MAXN];
int n;

void exchange(int i, int j){
    int temp = heaps[i];
    heaps[i] = heaps[j];
    heaps[j] = temp;
}

int maxHeapJudge(int i){
    int l = i*2;
    int r = l+1;
    int largest = i;
    if (l <= n && heaps[l] > heaps[i]){
        largest = l;
    }
    if (r <= n && heaps[r] > heaps[largest]){
        largest = r;
    }
    if (largest != i){
        exchange(i, largest);
        maxHeapJudge(largest);
    }
}

int makeHeap(){
    for (int i = n/2; i >=1; --i) {
        maxHeapJudge(i);
    }
}

void print(){
    for (int i = 1; i <= n; ++i) {
        printf(" %d", heaps[i]);
    }
    printf("\n");
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &heaps[i]);
    }
    makeHeap();
    print();
}
/*
10
4 1 3 2 16 9 10 14 8 7

 */
