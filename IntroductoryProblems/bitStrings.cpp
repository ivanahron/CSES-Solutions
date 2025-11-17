#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll modPow(int base, ll exp, ll mod) {
  if (exp == 0) return 1 % mod;

  if (exp & 1) {
    return (base * modPow(base, exp - 1, mod)) % mod;
  } else {
    ll res = modPow(base, exp / 2, mod);
    return (res * res) % mod;
  }
}

int main() {
  int n;
  cin >> n;
  ll mod = 1000000000 + 7;

  ll res = modPow(2, n, mod);
  cout << res;
}