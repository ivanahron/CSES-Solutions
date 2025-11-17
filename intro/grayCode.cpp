#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string toBinary(ll n, int size) {
  if (n <= 0) {
    string ret(size, '0');
    return ret;
  };
  
  string ans = "";
  while (n > 0) {
    ans += to_string((n % 2));
    n /= 2;
  }

  while (ans.size() != size) ans += "0";
  reverse(ans.begin(), ans.end());

  return ans;
}


int main() {

  int n;
  cin >> n;
  for (int i = 0; i < 1 << n; i++) {
    ll num = i ^ (i >> 1);
    cout << toBinary(num, n) << '\n';
  }
  
}