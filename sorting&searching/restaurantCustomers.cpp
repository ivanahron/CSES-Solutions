#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll> &arrival, vector<ll> &leave) {
  int ans = 0;
  int curr = 0;
  int i = 0, j = 0;
  while (i < arrival.size() && j < leave.size()) {
    if (arrival[i] == leave[j]) {
      i++;
      j++;
    } else if (arrival[i] < leave[j]) {
      i++;
      curr++;
    } else {
      j++;
      curr--;
    }
    ans = max(ans, curr);
  }

  cout << ans;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  cin >> n;

  vector<ll> arrive(n);
  vector<ll> leave(n);

  for (int i = 0; i < n; i++) {
    cin >> arrive[i] >> leave[i];
  }

  sort(arrive.begin(), arrive.end());
  sort(leave.begin(), leave.end());

  solve(arrive, leave);
}