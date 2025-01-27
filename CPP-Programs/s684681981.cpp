#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N, WM; cin >> N >> WM;
    ll w0, v0; cin >> w0 >> v0;
    ll w1, w2, w3;
    w1 = w0 + 1;
    w2 = w1 + 1;
    w3 = w2 + 1;
    vector<ll> V0, V1, V2, V3; 
    V0.emplace_back(v0);
    for (int i = 1; i < N; i++) {
        ll w, v; cin >> w >> v;
        switch (w - w0) {
        case 0:
            V0.emplace_back(v);
            break;
        case 1:
            V1.emplace_back(v);
            break;
        case 2:
            V2.emplace_back(v);
            break;
        case 3:
            V3.emplace_back(v);
            break;
        default:
            fprintf(stderr, "This must not happen");
            exit(1);
        }
    }

    sort(V0.begin(), V0.end(), greater<ll>());
    if (V0.size() > 0) for (auto x = V0.begin() + 1; x != V0.end(); x++) {*x += *(x - 1);}
    sort(V1.begin(), V1.end(), greater<ll>());
    if (V1.size() > 0) for (auto x = V1.begin() + 1; x != V1.end(); x++) {*x += *(x - 1);}
    sort(V2.begin(), V2.end(), greater<ll>());
    if (V2.size() > 0) for (auto x = V2.begin() + 1; x != V2.end(); x++) {*x += *(x - 1);}
    sort(V3.begin(), V3.end(), greater<ll>());
    if (V3.size() > 0) for (auto x = V3.begin() + 1; x != V3.end(); x++) {*x += *(x - 1);}

    ll ma = 0;
    for (int i = 0; i <= V0.size(); i++) {
        for (int j = 0; j <= V1.size(); j++) {
            for (int k = 0; k <= V2.size(); k++) {
                for (int m = 0; m <= V3.size(); m++) {
                    ll W = w0 * i + w1 * j + w2 * k + w3 * m;
                    if (W > WM) break;
                    ll V = 0;
                    if (i > 0) V += V0[i-1];
                    if (j > 0) V += V1[j-1];
                    if (k > 0) V += V2[k-1];
                    if (m > 0) V += V3[m-1];
                    ma = max(ma, V);
                }
            }
        }
    }
    cout << ma << endl;
}
