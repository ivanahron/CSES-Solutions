#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  cout << 0 << '\n';
  for (int i = 2; i <= n; i++) {
    ll n = i * i;
    cout << ((n * (n - 1)) / 2) - (4 * (i - 1) * (i - 2)) << '\n';
  }
}