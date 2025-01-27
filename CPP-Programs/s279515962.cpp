
#include <bits/stdc++.h>
#include <iostream>
#include <string>

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;

#define REP(idx, N) for (u64 idx = 0; idx < N; idx++)

int main() {
  i32 a, b, c, d;
  cin >> a >> b >> c >> d;

  while (a > 0 && c > 0) {
    c = c - b;
    if (c <= 0) {
      cout << "Yes";
      return 0;
    }

    a = a - d;
    if (a <= 0) {
      cout << "No";
      return 0;
    }
  }
}
