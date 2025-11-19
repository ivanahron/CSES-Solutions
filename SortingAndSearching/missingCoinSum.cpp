#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20

const int MAX_N = 2 * 1e5;
ll arr[MAX_N];

ll solve(int n) {
  ll total = arr[0];
  if (total > 1) return 1;

  for (int i = 1; i < n; i++) {
    ll diff = arr[i] - total;
    if (diff > 1) {
      return total + 1;
    }
    total += arr[i];
  }

  return total + 1;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(begin(arr), begin(arr) + n);
  cout << solve(n);
}