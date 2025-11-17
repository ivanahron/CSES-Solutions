#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> getBound(ll num, ll &digitsBefore, int &length) {
  pair<ll, ll> ans(1, 9);

  ll i = ans.first, j = ans.second;
  
  ll digitCnt = j - i + 1;
  while (digitCnt < num) {
    length++;
    i *= 10;
    j = (j + 1) * 10 - 1;
    digitsBefore = digitCnt;
    digitCnt += length * (j - i + 1);
  }

  ans.first = i; ans.second = j;
  return ans;
}

int main() {
  int q;
  cin >> q;
  
  for (int i = 0; i < q; i++) {
    ll k;
    cin >> k;
    ll digitsBefore = 0;
    int length = 1;

    pair<ll, ll> bound = getBound(k, digitsBefore, length);
    ll offset = (k - digitsBefore - 1);

    string num = to_string(bound.first + offset / length);
    cout << num[offset % length] << '\n';
  }
}