#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

int testcase_ends() {
  char buf[128];
  fgets(buf, sizeof buf, stdin);
  std::string s=buf;
  if (s[0] == '.') {
    return 1;
  }

  std::stack<char> k;
  for (char ch: s) {
    if (ch == '(') {
      k.push(')');
    } else if (ch == '[') {
      k.push(']');
    } else if (ch == ')' || ch == ']') {
      if (k.empty()) 
        return !printf("no\n");
      if (k.top() == ch) {
        k.pop();
      } else {
        printf("no\n");
        return 0;
      }
    } 
  }
  printf("%s\n", k.empty()? "yes":"no");
  return 0;
}

int main() {
  while (!testcase_ends()) {}
}

