#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 0;
  while (n / 5 > 0) {
    n /= 5;
    ans += n;
  }

  cout << ans;
}
