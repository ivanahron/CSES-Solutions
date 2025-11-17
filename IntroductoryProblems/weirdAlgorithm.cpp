#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  cout << n << ' ';
  while (n != 1) {
    if (!(n & 1)) {
      n >>= 1;
    } else {
      n *= 3;
      n++;
    }

    if (n >= 1) {
      cout << n;
    }

    if (n > 1) cout << ' ';
  }
}
