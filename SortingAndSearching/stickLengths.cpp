#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20

const int MAX_N = 2 * 1e5;
ll arr[MAX_N];

void solve(int n, int mid) {
  ll ans = 0;

  for (int i = 0 ;i < n; i++) {
    ans += abs(arr[i] - arr[mid]);
  }

  cout << ans;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int mid = n / 2;
  sort(begin(arr), begin(arr) + n);

  solve(n, mid);
}
