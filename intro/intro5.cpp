#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (1 < n && n <= 3) cout << "NO SOLUTION";
  else {
    for (int i = 2; i <= n; i += 2) cout << i << ' ';
    for (int i = 1; i <= n; i += 2) {
      cout << i;

      if (i + 2 <= n) cout << ' ';
    }
  }
}