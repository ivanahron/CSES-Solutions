#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20

const int MAX_N = 2 * 1e5 + 5;
ll arr[MAX_N];

void solve(int n) {
  int ans = 0;
  multiset<ll> towers = {};

  for (int i = 0; i < n; i++) {
    ll curr = arr[i];
    auto up = towers.upper_bound(curr);
    if (up == towers.end() || towers.size() == 0) {
      ans++;
    } else {
      towers.erase(up);
    }
    towers.insert(curr);
  }

  cout << ans;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];
  solve(n);
}