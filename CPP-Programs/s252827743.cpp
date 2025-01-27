#include <bits/stdc++.h>
using namespace std;
using ll = long long;


bool vector_finder(std::vector<ll> vec, ll number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) {
    return true;
  }
  else {
    return false;
  }
}


int main() {
    ll A, B, K;

    cin >> A >> B >> K;

    vector<ll> div;

    for (ll i = 100; i >= 1; i--) {
      if ((A%i == 0) && (B%i == 0)) div.push_back(i);
    }
    
    cout << div.at(K-1) << endl;
    
    
    return 0;
}