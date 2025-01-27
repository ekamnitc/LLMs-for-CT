#include <iostream>

using namespace std;

#define MAX_N 200000

// 入力
int N;
int a[MAX_N];

int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    long long sunuke_sum = 0;
    long long araiguma_sum = 0;
    for (int i = 0; i < N; ++i) {
        araiguma_sum += a[i];
    }
    long long dif_of_abs = 1e15;

    for (int i = 0; i < N - 1; ++i) {
        sunuke_sum += a[i];
        araiguma_sum -= a[i];
        dif_of_abs = min(dif_of_abs, abs(sunuke_sum - araiguma_sum));
    }

    cout << dif_of_abs << endl;

    return 0;
}