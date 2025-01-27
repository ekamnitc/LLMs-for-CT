#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    double p[n];
    double sum = 0.0, maxSum = 0.0;
    for (int i=0; i<n; i++) {
        cin >> p[i];
        sum += (p[i]+1.0)/2.0;
        if (i-k >= 0) {
            sum -= (p[i-k]+1.0)/2.0;
        }
        maxSum = max(maxSum, sum);
    }
    cout << fixed;
    cout << setprecision(6);
    cout << maxSum << endl;
}