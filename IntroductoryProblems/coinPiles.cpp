#include <bits/stdc++.h>
using namespace std;

string coin_piles(int a, int b) {
  if ((a + b) % 3 == 0 && (min(a, b) >= max(a, b) / 2)) return "YES";
  return "NO";
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    cout << coin_piles(a, b);

    if (i != t - 1) cout << '\n';
  }
}