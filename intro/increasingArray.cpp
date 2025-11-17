#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[200005];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];

  ll ans = 0;

  for (int i = 1; i < n; i++) {
    int curr = arr[i], prev = arr[i - 1];

    if (curr < prev) {
      ll diff = (prev - curr);
      arr[i] += diff;
      ans += diff;
    } 
  }

  cout << ans;
}
