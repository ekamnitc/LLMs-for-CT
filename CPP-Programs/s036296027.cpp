#include <bits/stdc++.h>
using namespace std;

int main() {
 string eso;
 cin >> eso;
  if (eso == "SSS"){
    cout << 0;
  }
    if (eso == "RSS"){
    cout << 1;
  }
    if (eso == "SRS"){
    cout << 1;
  } if (eso == "SSR"){
    cout << 1;
  } if (eso == "SRR"){
    cout << 2;
  } if (eso == "RRS"){
    cout << 2;
  } if (eso == "RSR"){
    cout << 1;
  } if (eso == "RRR"){
    cout << 3;
  }
  
	return 0;
}