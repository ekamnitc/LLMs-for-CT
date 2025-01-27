#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

int main() {
        int H, W, h, w;
        scanf("%d%d%d%d", &H, &W, &h, &w);
        if (W % w == 0 && H % h == 0) {
                puts("No");
                return 0;
        }
        puts("Yes");
        bool unko = false;
        if (W % w == 0) {
                swap(W, H);
                swap(w, h);
                unko = true;
        }
        vector<int> tozan(W, 100000000), gezan(W);
        tozan[w - 1] = -100000000;
        for (int i = w; i < W; i ++) tozan[i] = tozan[i - w] - 1;
        for (int i = 0; i < W; i ++) gezan[i] = tozan[i] + (i ? -tozan[i - 1] : 0);
        if (unko) {
                for (int i = 0; i < W; i ++) {
                        for (int j = 0; j < H; j ++) cout << gezan[i] << ' '; cout << endl;
                }
        } else {
                for (int i = 0; i < H; i ++) {
                        for (int j = 0; j < W; j ++) cout << gezan[j] << ' '; cout << endl;
                }
        }
        return 0;
}

