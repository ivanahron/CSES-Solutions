#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20

const int MAX_N = 2 * 1e5;
ll arr[MAX_N];

void solve(int n) {
  ll global_max = arr[0];
  ll curr_max = arr[0];

  for (int i = 1; i < n; i++) {
    ll take = curr_max + arr[i], justNew = arr[i];
    if (justNew > take) {
      curr_max = justNew;
    } else {
      curr_max = take;
    }
    global_max = max(global_max, curr_max);
  }

  cout << global_max;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  solve(n);
}