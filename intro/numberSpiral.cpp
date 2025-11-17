#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    ll x, y;
    cin >> x >> y;

    ll ref = max(x, y);
    ll base_val = ref * ref;

    if (ref & 1) {
      if (y == ref) base_val -= (x - 1);
      else base_val -= (ref + (ref - 1 - y));
    } else {
      if (x == ref) base_val -= (y - 1);
      else base_val -= (ref + (ref - 1 - x));
    }

    cout << base_val;
    
    if (i != t - 1) cout << '\n';
  }
}